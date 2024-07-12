## Translations in qgc <br>

Strings to be translated, marked with the tr() and qstr() methods for C++ and qml respectively, are stored in .json files. To update translations there is a parser [python json parser](https://github.com/mavlink/qgroundcontrol/blob/master/translations/qgc-lupdate-json.py), which searches all .json files, collects strings for translation and converts an xml file located in the translations folder into qgc.ts.

### Transfer methods
QGC uses Qt Linguist's string translation mechanisms.

* To set the translation manually, you can use qt linguist located in the Qt/tools folder
> Important: each language has its own qgc_source_.._.. .ts file, which needs to be edited to translate the interface into the desired language.

###### For Linux, you can download translation tool packages using
```
sudo apt-get install qttools5-dev-tools
```
###### and run in terminal
```
linguist
```
---
* Also, there is a python script tr.py in the same folder with which you can translate the entire interface.
This requires:
1. ###### Install the Google Translate API python library
```
pip install googletrans==4.0.0rc1
```
2. ###### Run in the terminal, specifying the arguments (path to the script, "path to the translation file", source language, language for translation) for example like this:

```
python3 ~/qgroundcontrol/translations/tr.py "~/qgroundcontrol/translations/qgc_source_el_GR.ts" en ru
```
## qgc assembly and video streaming
## Android build
* ### Install and run Qt
[qt installer](https://www.qt.io/download-open-source)
> Required Qt version - 6.6.3

##### For Ubuntu
1.Set the downloaded file to executable using: chmod +x.
2. You may also need to install libxcb-cursor:
```
sudo apt install libxcb-cursor0
```
* ### Select components to install
>To view a complete list of all available components in Setup's Select Components dialog box, you may need to select the Archive checkbox in the right column under the Categories tab, then click Filter.

1. **In the _Qt 6.6.3 section, select:**
* Android: Android
* Qt 5 Compatibility Module
* Qt Shader Tools
* Qt Quick 3D
---
2. **In the Additional Libraries section, select:**
	* Qt Charts
	* Qt Connectivity
	* Qt Location (TP)
	* Qt Multimedia
	* Qt Positioning
	* Qt Sensors
	* Qt Serial Port
	* Qt Speech
---
3. **Installing additional packages for the Android platform:**
* **Jdk**
>QGC supports java 17 and higher.

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
* **Android SDK Command Line Tools**
1.Download the latest version for your operating system [Android SDK command line tools](https://developer.android.com/studio/#command-line-tools-only)
2.Unpack to the appropriate path:
	* #### Linux: ~/Android/Sdk/
	* #### macOS: ~/Library/Android/sdk/
  	or
  	```
  	brew install android-commandlinetool
  	```
  	* #### Windows: C:\Users\<USER>\AppData\Local\Android\Sdk\

>You can also install the official integrated development environment (IDE) for Android app development and configure the following packages to be built through the app. [android-studio](https://developer.android.com/studio).

* **Required Android SDKs (Platform SDK, Platform Tools, and Build Tools)**
```
sdkmanager "platform-tools" "platforms;android-34" "build-tools;34.0.0"
```
* **Android NDK**
Qt 6.6 uses ndk 25.1.8937393, it can be installed by running:
```
sdkmanager "ndk;26.1.10909125"
```
> More information can be found here [Qt-android](https://doc.qt.io/qt-6/android-getting-started.html)
---
4. **Video Streaming:**
* Download gstreamer from here: [gstreamer-1.0-android-universal-1.18.6.tar.xz](https://gstreamer.freedesktop.org/pkg/android/1.18.6/)
* Create a directory called "gstreamer-1.0-android-universal-1.22.11" in the qgroundcontrol root directory (where qgroundcontrol.pro is located). Unpack the downloaded archive into this directory. This is where the build system will look for it. Make sure your archiving tool does not create additional top-level directories. The structure after unpacking the archive should look like this:
```
qgroundcontrol
├── gstreamer-1.0-android-universal-1.22.11
│ │
│   ├──armv7
│   │   ├── bin
│   │   ├── etc
│   │   ├── include
│   │   ├── lib
│   │   └── share
│   ├──x86
```
---
5. **Building using Qt Creator:**

* Launch Qt Creator, select Open Project and select the CMakeLists.txt file.

* In the Projects section, select for Android:
__armeabi-v7a (GCC 4.9, Qt 6.6.3)__
> Requires JDK17. You can confirm that it is in use by looking at your project settings: Projects > Manage Sets > Devices > Android (tab) > Android Settings > JDK Location. In the same window you can check the SDK and NDK.

* Building using the "hammer" (or "play") icons:

![png](https://docs.qgroundcontrol.com/master/assets/qt_creator_build_qgc.ACO6OjKV.png)