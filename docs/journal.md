## 17.06.2025

- Bugün kendi 3D oyun motorumu yapmaya karar verdim. İlk adım olarak araştırmalarımı yaptım. Platform bağımsız, en düşük sistemlerde bile çalışabilecek bir motor geliştirmek istiyorum (2GB ekran kartı, i5 işlemci). Motoru denerken geliştirmek istediğim oyun Minecraft; basitliği ve minimum sistem gereksinimleri istediği için amacıma uygun olduğunu düşünüyorum.

- C++ ve OpenGL ile ilerleyeceğim.
- Herhangi bir platforma özel geliştirilmiş bir library kullanmayarak "platform bağımsızlık" ilkesini sağlayacağım. Örnek: GLFW, GLM gibi OpenGL kütüphaneleri. 
- IDE olarak VS Code kullanacağım; yine basitliği/hemen her platformda sorunsuz çalışması ve CMake için kolaylıklarından dolayı seçtim.

- Başlangıç klasör yapısı şu şekilde:
    - /assets
    - /build
    - /docs
    - /engine
        - Engine.h
        - Engine.cpp
        - CMakeLists.txt
    - /external
    - /game
        - main.cpp
        - CMakeLists.txt
    - /include
    - .gitignore
    - CMakeLists.txt
    - README.md

- İlk adımlar olarak "Engine.h/cpp, main.cpp" ve CMake konfigürasyonlarımı yaparak oldukça basit bir yapı oluşturdum.
    - Executable yolu: /build/game/debug/main_game.exe

- Şu anki adım OpenGL ile ekranda bir üçgen, kare vb. bir çıktı alıp onu manipüle etmek olacak. Bunun için gerekli GLFW kütüphanesini kurdum.

## 18.06.2025
- Yeni bir proje oluşturdum "Zengine Vol2" şeklinde çünkü YouTube'da bulduğum bir game engine tutorial playlist'ini takip etmeye karar verdim başlangıç olarak:
    - [The Cherno - Game Engine](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT)

- Bu kursta Visual Studio, OpenGL/C++ kullanılıyor. Başlangıç yapımı buna göre oluşturursam ileride daha az başım ağrır diye düşünüyorum. Sonuçta bu yapıya istediğimi ekleyip çıkarabilirim.

- Şimdiye kadar oldukça basit bir yapı ve "entry point" oluşturdum. Sırada "logging" sistemi var. Bunun için sıfırdan bir loglama kütüphanesi yazmak yerine, GitHub'da var olan şu repo'yu kullanacağım:
    - [SPDLog by Gabime](https://github.com/gabime/spdlog)
    - Repo'yu kendime göre uyarlamak için bir Log class'ı oluşturup o şekilde kullandım.

- Şu ana kadar hep Visual Studio ile ve Windows'a göre derlemeler/ayarlamalar vs. yaptım ama ben bu Zengine'in platform-independent olmasını istiyorum. Bunu sağlamak için farklı platformlar için de derleme yapabilmem lazım. Bunu da "premake" kullanarak yapacağım. CMake kullanmama sebebim The Cherno'nun gereksiz derecede kompleks bulmasından ötürü kullanmıyor olması.
    - [Premake](https://github.com/premake/premake-core)

- Premake ile compilation işlemini de hallettim. Şimdi sırada bir "event system" kurmak var. Bunun amacı user herhangi bir input girdiğinde (mouse, keyboard) ya da window'larla bir işlem yapmak istediğinde (open, close, resize, etc.), bu işlemleri asıl uygulamadan ayrı olarak işleyebilmek. Yani engine bir yana bu event system engine'den ayrı bir şekilde oluşturulmazsa proje büyüdüğünde bana daha fazla problem oluşturacak.
    - İleride "buffering" yaparak gelen event'leri bir queue'ya koymak ve belli bir frame sonra işlemek daha doğru olabilir.

- Şimdi sırada bir window başlatmak var. Bunun için ilk versiyonda yaptığım gibi OpenGL kütüphanesi olan GLFW kullanacağım.
    - [GLFW](https://github.com/glfw/glfw)

## 20.06.2025
- Kaldığım yerden devam ediyorum window başlatmak işine.
    - Yaptığım aslında "window abstraction" oluşturmak çünkü ben bu engine'in cross-platform olmasını istiyorum. Dolayısıyla bir abstraction oluşturup sonra her platform için bu interface'i implemente etmem lazım. Örnek vermek gerekirse Windows için ileride OpenGL kullanmak istemeyebilirim çünkü Windows'un kendi API'ı olan Win32 doğal olarak Windows için daha iyi bir seçenek. Aynı şekilde böyle platform-dependent customization'lar yapmak isteyebilirim, kimi özelliği sadece Linux için eklerim mesela ama hepsi ortak bir interface kullanırsa derli toplu, düzenli bir yapıda kalabilirim.
    - Şu anlık sadece Windows için implemente edildi interface.

## 06.07.2025
- 