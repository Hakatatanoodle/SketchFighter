#building SketchFighter on Windows

##Requirements

- windows 10/11 (64-bit)
- SFML 2.6.2 extracted to: `C:\libs\SFML-2.6.2`
  - `C:\libs\SFML-2.6.2\include`
  - `C:\libs\SFML-2.6.2\lib`
  - `C:\libs\SFML-2.6.2\bin`

  -winlibs MinGw-w64 toolchain (GCC 13.1.0) extracted to:  
  `C:\winlibs-sfml\mingw64\bin\g++.exe`

  ##Build Command

From the project root (`C:\yooo\SketchFighter\SketchFighter`):

```powershell
C:\winlibs-sfml\mingw64\bin\g++.exe src\main.cpp -IC:\libs\SFML-2.6.2\include -LC:\libs\SFML-2.6.2\lib -lsfml-graphics -lsfml-window -lsfml-system -o SketchFighter.exe

C:\winlibs-sfml\mingw64\bin\g++.exe -I include src\main.cpp -IC:\libs\SFML-2.6.2\include -LC:\libs\SFML-2.6.2\lib -lsfml-graphics -lsfml-window -lsfml-system -o SketchFighter.exe


C:\winlibs-sfml\mingw64\bin\g++.exe -I include src\main.cpp src\Player.cpp src\Enemy.cpp -IC:\libs\SFML-2.6.2\include -LC:\libs\SFML-2.6.2\lib -lsfml-graphics -lsfml-window -lsfml-system -o SketchFighter.exe
