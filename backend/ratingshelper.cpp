#include "ratingshelper.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QtMath>
#include <QDebug>

RatingsHelper *RatingsHelper::currentInstance = nullptr;

RatingsHelper *RatingsHelper::instance()
{
    if (!currentInstance) {
        currentInstance = new RatingsHelper;
    }
    return currentInstance;
}

RatingsHelper::RatingsHelper()
{
    QNetworkAccessManager *networkManager = new QNetworkAccessManager;
    QNetworkRequest request(QUrl("https://odrs.gnome.org/1.0/reviews/api/ratings"));
    networkManager->get(request);
    qDebug() << "[ RATINGS ] Fetching ratings...";
    connect(networkManager, &QNetworkAccessManager::finished, this, [ = ] (QNetworkReply *reply) {
        QByteArray data = reply->readAll();
        QJsonObject array = QJsonDocument::fromJson(data).object();
        for (const QString &key : array.keys()) {
            ratingsList.insert(key, array.value(key).toObject());
        }
        emit(fetched());
        available = true;
        qDebug() << "[ RATINGS ] Ratings fetched";
        disconnect(this, &RatingsHelper::fetched, nullptr, nullptr);
    });
}

double RatingsHelper::averageRating(QString app)
{
    double ratings = 0;
    ratings += ratingsList.value(app).value("star1").toInt();
    ratings += ratingsList.value(app).value("star2").toInt() * 2;
    ratings += ratingsList.value(app).value("star3").toInt() * 3;
    ratings += ratingsList.value(app).value("star4").toInt() * 4;
    ratings += ratingsList.value(app).value("star5").toInt() * 5;
    double rating = floor((ratings / totalRatings(app) * 2) + 0.5) / 2;
    if (rating != rating) {
        rating = 0;
    }
    return rating;
}

int RatingsHelper::totalRatings(QString app)
{
    int total = ratingsList.value(app).value("total").toInt();
    if (total != total) {
        total = 0;
    }
    return total;
}