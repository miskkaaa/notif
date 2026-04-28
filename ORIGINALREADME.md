# notif api for geometry dash
check out the https://forgejo.hlelo.cc/Miskaa/notif/releases (releases page) \

Also, over at https://forgejo.hlelo.cc/Miskaa/notif is the original source code with all the original commits, i need to migrate onto here since "local build; please use github actions." -- someone who reviewed my code

Enjoy the shitty readme.md file i made when its 11pm/midnight on a school day :3

## Usage:
### Regular:
In my notif api, theres something called *customizability* (if youre using fancy ofc), theres also predefined functions if youre lazy<br>
```cpp
void notif(const std::string& text, const std::string& type = "info");
void info(const std::string& text);    // info
void warn(const std::string& text);    // warning  
void error(const std::string& text);   // error
void loading(const std::string& text); // loading
void success(const std::string& text); // success
```
If you are dumb enough to not understand anything, theres ``notifapi::info``, ``notifapi::warn``, ``notifapi::error``, ``notifapi::loading``, ``notifapi::success`` etc.<br>
I've given out example screenshots in the screenshots section. didnt test out loading tho, but its just a loading bar you see when youre loading online levels<br>
<h6>theres also notifapi::notif if you want an info notification quickly without doing info, since its predefined in the header file</h6>

### Fancy oooo:
Yes. there's customizability, shockers.<br>
Check out the screenshots since i set some examples there.<br>
Header file code:
```cpp
void fnotif(const std::string& text, const std::string& type = "info", float time = 3.0f, cocos2d::ccColor3B accentColor = {0, 0, 0}, float scale = 1.0f, Position position = Position::TopRight, Animation animation = Animation::Slide, const std::string& customSound = "");
```
Again, if you're dumb, its basically ``notifapi::fnotif(example1, "info", 3.0f, cocos2d::ccColor3B{50, 125, 255}, 1.0f, notifapi::Position::TopRight, notifapi::Animation::Slide, "");`` (example)<br>
```cpp
notifapi::fnotif(example1, "info", 3.0f, cocos2d::ccColor3B{50, 125, 255}, 1.0f, notifapi::Position::TopRight, notifapi::Animation::Slide, "");

// example1 is a string, so it can be:
std::string example1 = "Hello from notif!";
notifapi::fnotif(example1, "info", 3.0f, cocos2d::ccColor3B{50, 125, 255}, 1.0f, notifapi::Position::TopRight, notifapi::Animation::Slide, "");
// or i guess you can just do this:
notifapi::fnotif("Hello from notif!", "info", 3.0f, cocos2d::ccColor3B{50, 125, 255}, 1.0f); // no std::string required

// the first 3.0f is the duration, so it can be 6.9f, 6.7f, 1.0f etc.
// cocos2d::ccColor3B is the RGB color code for the accent bar (aka the thing on the right)
/*
   Error RGB (ccColor3B) is 255, 50, 50 (as provided in the last error example)
   You can use any other RGB color
*/

// the last 1.0f is the scale, so it can be 0.5f (smaller), 1.5f (bigger), 2.0f (huge) etc.

/*
 notifapi::Position is any position
 ahem...
             case Position::TopRight:
                targetPos = cocos2d::CCPoint(winSize.width - size.width - margin, winSize.height - size.height - margin);
                startPos = cocos2d::CCPoint(winSize.width + 50, targetPos.y);
                break;
            case Position::TopLeft:
                targetPos = cocos2d::CCPoint(margin, winSize.height - size.height - margin);
                startPos = cocos2d::CCPoint(-50, targetPos.y);
                break;
            case Position::BottomRight:
                targetPos = cocos2d::CCPoint(winSize.width - size.width - margin, margin);
                startPos = cocos2d::CCPoint(winSize.width + 50, targetPos.y);
                break;
            case Position::BottomLeft:
                targetPos = cocos2d::CCPoint(margin, margin);
                startPos = cocos2d::CCPoint(-50, targetPos.y);
                break;
            case Position::TopCenter:
                targetPos = cocos2d::CCPoint(winSize.width/2 - size.width/2, winSize.height - size.height - margin);
                startPos = cocos2d::CCPoint(targetPos.x, winSize.height + 50);
                break;
            case Position::BottomCenter:
                targetPos = cocos2d::CCPoint(winSize.width/2 - size.width/2, margin);
                startPos = cocos2d::CCPoint(targetPos.x, -50);
                break;
            case Position::Center:
                targetPos = cocos2d::CCPoint(winSize.width/2 - size.width/2, winSize.height/2 - size.height/2);
                startPos = targetPos;
                break;
  thats stolen from the source code ^^^^^^
  theres these yeah
*/

/*
  theres also animations but Slide, Elastic and None work only, sad 3:
*/
```
Also, since i included my <a href="https://github.com/miskkaaa/mUtils">mUtils</a> project into here. you can do this:
```cpp
mutils::DelayedTask::wait(5.0f, []() {
    notifapi::warn("this is a warning, be scared, something went wrong OwO");
});
```
All you really need to know is: ``5.0f`` is the time

### Including etc.
To include <a href="https://github.com/miskkaaa/mUtils">mUtils</a>, you can git clone the repo, or just copy this entire repository as it is right now \
Then, in your source file:
```cpp
#include "includes/mutils/index.hpp"
```
the ``"includes/mutils"`` path can be anywhere, as long it contains the ``index.hpp`` file and ``qol``, ``string``, ``ui`` folders \
<br>
To include the notif file, you either put
```json
  "dependencies": {
    "geode.node-ids": ">=v1.23.3",
    "miskaa.notif": ">=1.0.1",
  }
```
in your mod.json file (not supported)\
**OR:**
1. clone this repository
2. copy the ``src/`` folder into like ``include/notif`` in your geode mod
3. put:
```cpp
#include "includes/notif/includes/notif.hpp"
```
<h6>or anywhere where notif.hpp is at</h6>

### Using mUtils and notif
First, you have to copy everything (git clone the repo), with the steps above (Including etc.) \
Then, you need to include these:
```cpp
#include "includes/notif/includes/notif.hpp"        // wherever notif.hpp is located at
#include "includes/notif/includes/mutils/index.hpp" // wherever index.hpp, ui, qol, string folders are at
```
Secondary, do anything you want! \
There isnt really any docs on mUtils except for this and the repo (which is the readme file in there), You can read the source code since i dont care. \ 
```cpp
/*
  Again, i put an example somewhere above everything i forgot where
*/
mutils::DelayedTask::wait(5.0f, []() {
    notifapi::warn("this is a warning, be scared, something went wrong OwO");
});
// mutils::DelayedTask is basically a wait function, 5.0f is the delay/wait time
```

## Screenshots:
### Info example:
```cpp
notifapi::info(example1)
// OR
notifapi::fnotif(example1, "info", 3.0f, cocos2d::ccColor3B{50, 125, 255}, 1.0f);
```
![info](https://forgejo.hlelo.cc/Miskaa/notif/raw/branch/main/screenshots/s1.png)

### Successs example:
```cpp
notifapi::success(example2);
// OR
notifapi::fnotif(example2, "success", 3.0f, cocos2d::ccColor3B{50, 255, 50}, 1.0f);
```
![success](https://forgejo.hlelo.cc/Miskaa/notif/raw/branch/main/screenshots/s2.png)

### Warning example:
```cpp
notifapi::warn(example3);
// OR
notifapi::fnotif(example3, "warn", 3.0f, cocos2d::ccColor3B{255, 200, 50}, 1.0f);
```
![warning](https://forgejo.hlelo.cc/Miskaa/notif/raw/branch/main/screenshots/s3.png)

### Error example:
```cpp
notifapi::error(example4);
// OR
notifapi::fnotif(example4, "error", 3.0f, cocos2d::ccColor3B{255, 50, 50}, 1.0f);
```
![error](https://forgejo.hlelo.cc/Miskaa/notif/raw/branch/main/screenshots/s4.png)
