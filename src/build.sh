g++ -g -I/usr/include \
    main.cpp \
    SXShape.cpp \
    SXTexture.cpp \
    SXSurface.cpp \
    SXRender.cpp \
    SXWindow.cpp \
    SXText.cpp \
    SXBMPSurface.cpp \
    `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
