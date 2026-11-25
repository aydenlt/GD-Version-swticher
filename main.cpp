
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
        title->setPosition({ 160, 120 });
        this->addChild(title);

        auto menu = CCMenu::create();

        const char* versions[] = {
            "2.207",
            "2.2081",
            "2.2091"
        };

        int selected = Mod::get()->getSavedValue<int>(
            "selected-version", 1
        );

        for (int i = 0; i < 3; i++) {
            auto label = CCLabelBMFont::create(
                versions[i],
                "bigFont.fnt"
            );

            label->setScale(0.6f);

            auto button = CCMenuItemLabel::create(
                label,
                [i](CCObject*) {
                    Mod::get()->setSavedValue<int>(
                        "selected-version", i
                    );

                    FLAlertLayer::create(
                        "Version selected",
                        "Selection saved!\n"
                        "This does not change the installed game version.",
                        "OK"
                    )->show();
                }
            );

            if (i == selected)
                label->setColor({ 0, 255, 0 });

            menu->addChild(button);
            button->setPosition({
                0,
                35.0f - (i * 45.0f)
            });
        }

        menu->setPosition({ 160, 55 });
        this->addChild(menu);

        auto credit = CCLabelBMFont::create(
            "Created by aydenlt!",
            "goldFont.fnt"
        );
        credit->setScale(0.4f);
        credit->setPosition({ 160, 10 });
        this->addChild(credit);

        retu
            rn true;
    }
};
