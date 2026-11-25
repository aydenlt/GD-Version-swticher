
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(VersionSwitcherMenu, MenuLayer) {

    bool init() {
        if (!MenuLayer::init())
            return false;

        auto title = CCLabelBMFont::create(
            "GD VERSION SWITCHER",
            "bigFont.fnt"
        );

        title->setScale(0.55f);
        title->setPosition({ 160, 115 });
        this->addChild(title);

        auto info = CCLabelBMFont::create(
            "Select a Geometry Dash version",
            "goldFont.fnt"
        );

        info->setScale(0.4f);
        info->setPosition({ 160, 90 });
        this->addChild(info);

        auto menu = CCMenu::create();

        const char* versions[] = {
            "2.207",
            "2.2081",
            "2.2091"
        };

        for (int i = 0; i < 3; i++) {
            auto label = CCLabelBMFont::create(
                versions[i],
                "bigFont.fnt"
            );

            label->setScale(0.55f);

            auto button = CCMenuItemLabel::create(
                label,
                [i](CCObject*) {
                    Mod::get()->setSavedValue<int>(
                        "selected-version", i
                    );

                    FLAlertLayer::create(
                        "Version selected",
                        "Selection saved!\n"
                        "This does not install or switch the APK.",
                        "OK"
                    )->show();
                }
            );

            menu->addChild(button);
            button->setPosition({
                0,
                35.0f - (i * 45.0f)
            });
        }

        menu->setPosition({ 160, 40 });
        this->addChild(menu);

        auto credit = CCLabelBMFont::create(
            "Created by aydenlt!",
            "goldFont.fnt"
        );

        credit->setScale(0.4f);
        credit->setPosition({ 160, 10 });
        this->addChild(credit);

        re
            turn true;
    }
};
