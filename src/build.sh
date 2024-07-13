g++ -g -I/usr/include -I../include\
    main.cpp \
    SXShape.cpp \
    SXTexture.cpp \
    surface/SXSurface.cpp \
    SXRender.cpp \
    SXWindow.cpp \
    surface/SXText.cpp \
    surface/SXBMPSurface.cpp \
    `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
