DIR_3rd=$(dirname $(readlink -f "$0"))
ROOT_DIR=$(dirname ${DIR_3rd})
SDL_DIR=${ROOT_DIR}/3rd/SDL-release-2.28.5
if [ ! -d ${SDL_DIR} ];then
    tar zxvf SDL-release-2.28.5.tar.gz
fi
cd ${SDL_DIR}
./configure --prefix=${ROOT_DIR}/output/sdl
make && make install
