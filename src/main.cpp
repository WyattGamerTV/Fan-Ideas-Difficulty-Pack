#include <Geode/Geode.hpp>
#include <Geode/modify/GJDifficultySprite.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <string>

using namespace geode::prelude;

class $modify(MyDifficultySprite, GJDifficultySprite) {
    void updateFeatureSprite(int difficultyID) {
        GJDifficultySprite::updateFeatureSprite(difficultyID);

        if (difficultyID >= 11) {
            std::string frameName = "difficulty_" + std::to_string(difficultyID) + ".png";
            auto mySpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName.c_str());
            
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

            size_t pos = desc.find("[DIFF ");
            if (pos != std::string::npos) {
                size_t endPos = desc.find("]", pos);
                if (endPos != std::string::npos) {
                    std::string idStr = desc.substr(pos + 6, endPos - (pos + 6));
                    try {
                        int customID = std::stoi(idStr);
                        this->m_ratings = customID;
                        this->m_isDemon = true; 
                    } catch (...) {}
                }
            }
        }
        return true;
    }
};
