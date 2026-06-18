#include <Geode/Geode.hpp>
#include <Geode/modify/GJDifficultySprite.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <string>

using namespace geode::prelude;

class $modify(MyDifficultySprite, GJDifficultySprite) {
    void updateFeatureSprite(int difficultyID) {
        GJDifficultySprite::updateFeatureSprite(difficultyID);

        if (difficultyID == 11) {
            auto mySpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("difficulty_casual.png");
            if (mySpriteFrame) {
                this->setDisplayFrame(mySpriteFrame);
            }
        }
        else if (difficultyID == 12) {
            auto mySpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("difficulty_grandmaster.png");
            if (mySpriteFrame) {
                this->setDisplayFrame(mySpriteFrame);
            }
        }
        else if (difficultyID == 99) {
            auto mySpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("difficulty_god.png");
            if (mySpriteFrame) {
                this->setDisplayFrame(mySpriteFrame);
            }
        }
    }
};

class $modify(MyGameLevel, GJGameLevel) {
    bool init() {
        if (!GJGameLevel::init()) return false;

        if (this->m_creatorName == "WyattGamerTV") {
            std::string desc = this->m_levelDesc;

            if (desc.find("[GOD]") != std::string::npos) {
                this->m_ratings = 99;
                this->m_isDemon = true;
                this->m_isEpic = true;
            }
        }
        return true;
    }
};
