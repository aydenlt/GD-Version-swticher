
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(VersionSwitcherMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto label = CCLabelBMFont::create(
            "GD VERSION SWITCHER",
            "bigFont.fnt"
        );

        auto button = CCMenuItemLabel::create(
            label,
            [](CCObject*) {
                FLAlertLayer::create(
                    "GD Version Switcher",
                    "Geometry Dash Version Switcher\n"
                    "Created by aydenlt!",
                    "OK"
                )->show();
            }
        );

        auto menu = CCMenu::create();
        menu->addChild(button);
        menu->setPosition({ 150, 35 });
        this->addChild(menu);

        return true;
    }
};
