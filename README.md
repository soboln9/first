# My projects
# QGroundControl
## Translations in qgc <br>

Строки для перевода, помеченные методами tr() и qstr() для c++ и qml соответственно, хранятся в .json файлах. Для обновления переводов есть парсер [python json parser](https://github.com/mavlink/qgroundcontrol/blob/master/translations/qgc-lupdate-json.py), который ищет все .json файлы, собирает строки для перевода и преобразует в qgc.ts файл формата xml, находящийся в папке translations. 

### Способы перевода 
QGC использует механизмы Qt Linguist для перевода строк. 

* Чтобы установить перевод вручную можно использовать qt linguist находяящаяcя в папке Qt/tools
> Важно:для каждого языка существует свой qgc_source_.._.. .ts файл, который и нужно редактировать для перевода интерфейса на нужный язык.

###### Для Linux можно подгрузить пакеты инструментов для перевода с помощью
```
sudo apt-get install qttools5-dev-tools
```
###### и запустить в терминале
```
linguist
```
---
* Также, существует python-скрипт tr.py в той же папке с помощью которого можно перевести весь интерфейс. 
Для этого требуется: 
1. ###### Установить библиотеку python API Google Translate
``` 
pip install googletrans==4.0.0rc1
```
2. ###### Запустить в терминале, указав аргументы (путь к скрипту, "путь к файлу перевода", исходный язык, язык для перевода) например так:

``` 
python3 ~/qgroundcontrol/translations/tr.py "~/qgroundcontrol/translations/qgc_source_el_GR.ts" en ru
```
## Сборка qgc и видеостриминг
## Android build
* ### Установите и запустите Qt
[установщик qt](https://www.qt.io/download-open-source)
> Требуемая версия Qt - 6.6.3

##### Для Ubuntu
1.Установите для загруженного файла значение исполняемый файл, используя: chmod +x.
2. Вам также может потребоваться установить libxcb-cursor:
```
sudo apt install libxcb-cursor0
```
* ### Выберите компоненты для установки
>Чтобы просмотреть полный список всех доступных компонентов в диалоговом окне "Выбор компонентов" программы установки, вам может потребоваться установить флажок "Архивировать" в правой колонке под вкладкой "Категории", затем нажать на "Фильтр".

1. **В разделе _Qt 6.6.3 выберите:**
* Android: Android
* Qt 5 Compatibility Module
* Qt Shader Tools
* Qt Quick 3D
---
2. **В разделе Дополнительные библиотеки выберите:**
	* Qt Charts
	* Qt Connectivity
	* Qt Location (TP)
	* Qt Multimedia
	* Qt Positioning
	* Qt Sensors
	* Qt Serial Port
	* Qt Speech
---
3. **Установка дополнительных пакетов для платформы Android:**
* **Jdk**
>QGC поддерживает java 17 и выше.

#### Linux:
```
sudo apt-get install openjdk-17-jdk
nano ~/.bashrc
export JAVA_HOME=/usr/lib/jvm/java-17-openjdk-amd64
```
#### macOS:
```
brew install openjdk@17
sudo ln -sfn "$(brew --prefix openjdk@17)/libexec/openjdk.jdk" \
    "/Library/Java/JavaVirtualMachines/openjdk-17.jdk"
export JAVA_HOME="$(/usr/libexec/java_home -v 17)"
```
* **Инструменты командной строки Android SDK**
1.Загрузите последнюю версию для вашей операционной системы [Android SDK command line tools](https://developer.android.com/studio/#command-line-tools-only)
2.Распакуйте по соответсвующему пути:
	* #### Linux: ~ / Android / Sdk/
	* #### macOS: ~/Библиотека / Android / sdk/ 
	или 
	```
	brew install android-commandlinetool
	```
	* #### Windows: C:\Users \<ПОЛЬЗОВАТЕЛЬ>\AppData\Local \ Android \ Sdk\

>Также, можно установить официальную интегрированную среду разработки (IDE) для разработки приложений Android и настроить следующие пакеты для сборки через приложение. [android-studio](https://developer.android.com/studio).

* **Обязательные пакеты Android SDK(платформа SDK, инструменты платформы и инструменты сборки)**
```
sdkmanager "platform-tools" "platforms;android-34" "build-tools;34.0.0"
```
* **Android NDK**
В Qt 6.6 используется ndk 25.1.8937393, его можно установить запустив:
```
sdkmanager "ndk;26.1.10909125"
```
> Дополнительную информацию можно найти тут [Qt-android](https://doc.qt.io/qt-6/android-getting-started.html)
---
4. **Video Streaming:**
* Загрузите gstreamer отсюда: [gstreamer-1.0-android-universal-1.18.6.tar.xz](https://gstreamer.freedesktop.org/pkg/android/1.18.6/)
* Создайте каталог с именем «gstreamer-1.0-android-universal-1.22.11» в корневом каталоге qgroundcontrol (там, где находится qgroundcontrol.pro). Распакуйте загруженный архив в этот каталог. Вот где его будет искать система сборки. Убедитесь, что ваш инструмент архивирования не создает дополнительных каталогов верхнего уровня. Структура после распаковки архива должна выглядеть так:
```
qgroundcontrol
├── gstreamer-1.0-android-universal-1.22.11
│   │
│   ├──armv7
│   │   ├── bin
│   │   ├── etc
│   │   ├── include
│   │   ├── lib
│   │   └── share
│   ├──x86
```
---
5. **Сборка с использованием Qt Creator:**

* Запустите Qt Creator, выберите Открыть проект и выберите CMakeLists.txt файл.

* В разделе Проекты выберите для Android:
__armeabi-v7a (GCC 4.9, Qt 6.6.3)__
> Требуется JDK17. Вы можете подтвердить, что он используется, просмотрев настройки проекта: Проекты> Управление наборами> Устройства> Android (вкладка)> Настройки Android> Расположение JDK. В том же окне можно проверить SDK и NDK.

* Сборка с использованием значков "hammer" (или "play"):

![png](https://docs.qgroundcontrol.com/master/assets/qt_creator_build_qgc.ACO6OjKV.png)



















