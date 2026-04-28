#pragma once

#include <Geode/Geode.hpp>
#include <Geode/ui/Notification.hpp>
#include <queue>
#include <vector>

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
    
    void notify(const std::string& text, const std::string& type = "info");
    
    class queue : public cocos2d::CCObject {
    private:
        static queue* s_instance;
        std::queue<notif*> m_pending;
        std::vector<notif*> m_active;
        bool m_processing = false;
        static const int MAX_CONCURRENT = 3;
        
        queue() = default;
        
    public:
        static queue* get();
        void add(class notif* notification);
        void process();
        void done(class notif* notification);
        void update(float dt);
    };
    void info(const std::string& text);    // info
    void warn(const std::string& text);    // warning  
    void error(const std::string& text);   // error
    void loading(const std::string& text); // loading
    void success(const std::string& text); // success
    
    class notif : public cocos2d::CCNodeRGBA {
    protected:
        float m_time = 2.0f;
        float m_scale = 1.0f;
        Position m_position = Position::TopRight;
        Animation m_animation = Animation::Slide;
        std::string m_customSound = "";
        float m_volume = 1.0f;
        
        bool init(const std::string& text, const std::string& type, float time, cocos2d::ccColor3B accentColor, float scale, Position position, Animation animation, const std::string& customSound, float volume);
    public:
        static notif* create(const std::string& text, const std::string& type, float time = 3.0f, cocos2d::ccColor3B accentColor = {0, 0, 0}, float scale = 1.0f, Position position = Position::TopRight, Animation animation = Animation::Slide, const std::string& customSound = "", float volume = 1.0f);
        void show();
        void hide();
        void destroyed();
    };
    
    // fancyness
    void fnotif(const std::string& text, const std::string& type = "info", float time = 3.0f, cocos2d::ccColor3B accentColor = {0, 0, 0}, float scale = 1.0f, Position position = Position::TopRight, Animation animation = Animation::Slide, const std::string& customSound = "", float volume = 1.0f);
}
