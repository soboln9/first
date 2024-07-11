# My projects
# QGroundControl
## Translations in qgc <br>

Строки для перевода, помеченные методами tr() и qstr() для c++ и qml соответственно, хранятся в .json файлах. Для обновления переводов есть парсер [python json parser](https://github.com/mavlink/qgroundcontrol/blob/master/translations/qgc-lupdate-json.py), который ищет все .json файлы, собирает строки для перевода и преобразует в qgc.ts файл формата xml, находящийся в папке translations. 

### Способы перевода 
QGC использует механизмы Qt Linguist для перевода строк. 

* Чтобы установить перевод вручную можно использовать qt linguist находяящаяcя в папке Qt/tools
> Важно:для каждого языка существует свой qgc_source_.._.. .ts файл, который и нужно редактировать для перевода интерфейса на нужный язык.<br>
Для Linux можно подгрузить пакеты инструментов для перевода с помощью:
```
sudo apt-get install qttools5-dev-tools
```
и запустить в терминале:
```
linguist
```
---
* Также, существует python-скрипт tr.py в той же папке с помощью которого можно перевести весь интерфейс. 
Для этого требуется: 
1. Установить библиотеку python API Google Translate
``` 
pip install googletrans==4.0.0rc1
```
2. Запустить в терминале указав аргументы (путь к скрипту, "путь к файлу перевода", исходный язык, язык для перевода),например так:

``` 
python3 ~/qgroundcontrol/translations/tr.py "~/qgroundcontrol/translations/qgc_source_el_GR.ts" en ru
```