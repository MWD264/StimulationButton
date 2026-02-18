#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(StimLayer, MenuLayer) {

	bool init() {

		if (!MenuLayer::init()) {
			return false;

		}

		log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

		auto StimButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_button_01.png"),
			this,

			menu_selector(StimLayer::onStimButton)
		);
		auto menu = this->getChildByID("bottom-menu");

		menu->addChild(StimButton);

		StimButton->setID("my-button"_spr);
		menu->updateLayout();
		return true;
	}

	void onStimButton(CCObject*) {
		FLAlertLayer::create("Geode", "+1 Stimulation", "OK")->show();
	}
};