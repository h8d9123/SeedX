#ifndef SX_LOG_H
#define SX_LOG_H
#include "SXBasic.h"

#define SXLogSetPriority(priority) SDL_LogSetPriority(SDL_LOG_CATEGORY_CUSTOM, priority)
#define SXLogGetPriority SDL_LogGetPriority(SDL_LOG_CATEGORY_CUSTOM);
#if 1
#define __fmt__(fmt) "%s:%s:%d " fmt, __FILE__, __FUNCTION__, __LINE__
#else 
#define __fmt__(fmt) fmt
#endif
#define SXLogVerbose(fmt, args...)  SDL_LogVerbose(SDL_LOG_CATEGORY_CUSTOM, __fmt__(fmt), ##args)
#define SXLogDebug(fmt, args...)    SDL_LogDebug(SDL_LOG_CATEGORY_CUSTOM, __fmt__(fmt), ##args)
#define SXLogInfo(fmt, args...)     SDL_LogInfo(SDL_LOG_CATEGORY_CUSTOM, __fmt__(fmt), ##args)
#define SXLogWarn(fmt, args...)     SDL_LogWarn(SDL_LOG_CATEGORY_CUSTOM, __fmt__(fmt), ##args)
#define SXLogError(fmt, args...)    SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, __fmt__(fmt), ##args)
#define SXLogCtriical(fmt, args...) SDL_LogCritical(SDL_LOG_CATEGORY_CUSTOM, __fmt__(fmt), ##args)
#define SXLog(fmt, args...) SDL_Log(SDL_LOG_CATEGORY_CUSTOM, fmt, ##args)


#endif
