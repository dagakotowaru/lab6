Укажите пути к OpenCV:

    1. "Перейдите в свойства проекта: Правка → Свойства проекта."

    2. В разделе C/C++ → Общие → Дополнительные каталоги включаемых файлов добавьте:
    → C:\opencv\build\include

    3. В разделе Компоновщик → Общие → Дополнительные каталоги библиотек добавьте:
    → C:\opencv\build\x64\vc15\lib

    4. При необходимости укажите библиотеки OpenCV:
    → В разделе Компоновщик → Ввод → Дополнительные зависимости добавьте нужные библиотеки OpenCV. 
    Например:
    → opencv_world470.lib — для конфигурации Release.
    → opencv_world470d.lib — для конфигурации Debug.