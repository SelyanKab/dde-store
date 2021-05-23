<p align="center"><img src="https://user-images.githubusercontent.com/56656996/99621835-b2d8dc80-29dd-11eb-8183-987e80f8b3a7.png"></p>
<h1 align="center">DDE Store</h1>
<h3 dir='rtl' align="center">متجر تطبيقات لـ DDE مبني على DTK</h3>

<h2 dir='rtl' align="right">ما هذا؟</h2>

<p dir='rtl' align="right">هذا المتجر صمم ليعمل على واجهة Deepin في توزيعات اخرى. المتجر الاصلي في Deepin مبنى بطرقة عرض ويب ويحتوي على مستوداعات Deepin مما يجعله غير متوافق مع التوزيعات الأخرى. هذا المتجر مبنى على PackageKit و AppStream مما يجعله متوافق مع تقريبا جميع التوزيعات التي تحمل واجهة Deepin</p>

<h2 dir='rtl' align="right">Deepin</h2>
<p dir='rtl' align="right">هذا ينطبق على توزيعة Deepin فقط وليس على واجهة Deepin بشكل عام. توزيعة Deepin لا تدعم AppStream بشكل رسمي وهو ما يزود هذا المتجر بجميع البيانات اللازمة. **هذا المتجر غير مدعوم في توزيعة Deepin.** هذا المتجر مخصص ليعمل على التوزيعات التي تعمل بواجهة Deepin وليس على التوزيعة Deepin نفسها وبالتالي ليس لدي أي خطة لدعم توزيعة Deepin في هذا المتجر. في حال بدات Deepin بإستخدام AppStream، قد أقوم بتوفير الدعم. في حال كنت من مستخدمي Deepin وترغب في إستخدام متجر اخر، يمكنك تفقد مشارع رائعة أخرى مثل <a href="https://www.spark-app.store">Spark Store</a> أو <a href="https://deepines.com">Deepines Store</a>!</p>



<h2 dir='rtl' align="right">التثبيت</h2>
<h3 dir='rtl' align="right">UbuntuDDE</h3>

```
sudo add-apt-repository ppa:dekzi/ppa
sudo apt-get update
sudo apt-get install dde-store
```

<h3 dir='rtl' align="right">Arch</h3>

```
sudo pacman -S deepin-store
```

<h3 dir='rtl' align="right">البناء من الكود المصدري</h3>

<p dir='rtl' align="right"><b>إعتماديات (Ubuntu)</b></p>

<ul dir='rtl' align="right">
  <li dir='rtl' align="right">cmake</li>
  <li dir='rtl' align="right">qtbase5-dev</li>
  <li dir='rtl' align="right">qttools5-dev</li>
  <li dir='rtl' align="right">libdtkwidget-dev</li>
  <li dir='rtl' align="right">libdtkcore-dev</li>
  <li dir='rtl' align="right">libdtkgui-dev</li>
  <li dir='rtl' align="right">libpackagekitqt5-dev</li>
  <li dir='rtl' align="right">libappstreamqt-dev</li>
  <li dir='rtl' align="right">libsnapd-qt-dev</li>
</ul>

<p dir='rtl' align="right"><b>البناء</b></p>

```
git clone https://github.com/dekzi/dde-store.git
cd dde-store
cmake .
sudo make install
```

<h2 dir='rtl' align="right">المساهمة</h2>
<p dir='rtl' align="right">المساهمة في المشروع مرحب بها دائما سواء أكانت لإصلاح العيوب البرمجية، التحسينات، الترجمات أو أي شيء آخر!</p>

<h2 dir='rtl' align="right">الترخيص</h2>

<p dir='rtl' align="right"><a href="../../LICENSE">GPLv3</a></p>
