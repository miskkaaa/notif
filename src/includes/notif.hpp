#pragma once

#include <Geode/Geode.hpp>
#include <Geode/ui/Notification.hpp>

#ifdef GEODE_IS_WINDOWS
    #ifdef notif_EXPORTS
        #define NOTIF_API __declspec(dllexport)
    #else
        #define NOTIF_API __declspec(dllimport)
    #endif
#else
    #define NOTIF_API __attribute__((visibility("default")))
#endif

namespace notifapi {
    class notif;
    
    enum class Position {
        TopRight,
        TopLeft,
        BottomRight,
        BottomLeft,
        TopCenter,
        BottomCenter,
        Center
    };
    
    enum class Animation {
        Slide,
        Fade,
        Bounce,
        Elastic,
        Scale,
        None
    };
    
    NOTIF_API void notify(const std::string& text, const std::string& type = "info");
    
    NOTIF_API void info(const std::string& text);    // info
    NOTIF_API void warn(const std::string& text);    // warning  
    NOTIF_API void error(const std::string& text);   // error
    NOTIF_API void loading(const std::string& text); // loading
    NOTIF_API void success(const std::string& text); // success
    
    class NOTIF_API notif : public cocos2d::CCNodeRGBA {
    protected:
        float m_time = 2.0f;
        float m_scale = 1.0f;
        Position m_position = Position::TopRight;
        Animation m_animation = Animation::Slide;
        std::string m_customSound = "";
        float m_volume = 1.0f;
        
        bool init(const std::string& text, const std::string& type, float time, cocos2d::ccColor3B accentColor, float scale, Position position, Animation animation, const std::string& customSound, float volume, cocos2d::CCNode* customIcon);
    public:
        // customIcon: pass any CCNode* (CCSprite::create("path/outside/resources.png"))
        // itll be resized to 116x116, oh yeah pass nullptr to use the built-in type icon.
        static notif* create(const std::string& text, const std::string& type, float time = 3.0f, cocos2d::ccColor3B accentColor = {0, 0, 0}, float scale = 1.0f, Position position = Position::TopRight, Animation animation = Animation::Slide, const std::string& customSound = "", float volume = 1.0f, cocos2d::CCNode* customIcon = nullptr);
        void show();
        void hide();
    };
    
    // fancyness
    NOTIF_API void fnotif(const std::string& text, const std::string& type = "info", float time = 3.0f, cocos2d::ccColor3B accentColor = {0, 0, 0}, float scale = 1.0f, Position position = Position::TopRight, Animation animation = Animation::Slide, const std::string& customSound = "", float volume = 1.0f, cocos2d::CCNode* customIcon = nullptr);
}