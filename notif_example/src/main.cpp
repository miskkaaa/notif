#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <notif_api.hpp>

// Use notifications
$on_mod(Loaded) {
    mutils::DelayedTask::create(3.0f, []() {
        notifapi::info("Hello!");
    });
}