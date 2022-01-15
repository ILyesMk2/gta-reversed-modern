#include "StdInc.h"

#include "AEGlobalWeaponAudioEntity.h"
#include "AEAudioHardware.h"

CAESound* (&pWaterfall)[3] = *(CAESound * (*)[3])0xB612F0;
CAESound*& pFogHorn = *(CAESound**)0xB612FC;

// 0x5075B0
CAEGlobalWeaponAudioEntity::CAEGlobalWeaponAudioEntity() : CAEWeaponAudioEntity() {
    m_Physical = new CPhysical();
}

// 0x4DEF90
void CAEGlobalWeaponAudioEntity::UpdateParameters(CAESound* sound, int16 curPlayPos) {
    if (curPlayPos != -1)
        return;

    if (sound == pFogHorn) {
        pFogHorn = nullptr;
        return;
    }

    for (auto& waterfall : pWaterfall) {
        if (sound == waterfall) {
            waterfall = nullptr;
        }
    }
}

// 0x4DFAA0
void CAEGlobalWeaponAudioEntity::AddAudioEvent(eAudioEvents audioId, eWeaponType weaponType, CPhysical* entity) {
    if (!entity)
        return;

    switch (audioId) {
    case AE_WEAPON_FIRE:
    case AE_WEAPON_FIRE_PLANE:
        WeaponFire(weaponType, entity, audioId);
        break;
    case AE_WEAPON_RELOAD_A:
    case AE_WEAPON_RELOAD_B:
        WeaponReload(weaponType, entity, audioId);
        break;
    case AE_PROJECTILE_FIRE:
        ProjectileFire(weaponType, entity, audioId);
        break;
    default:
        return;
    }
}

// 0x4DF060
void CAEGlobalWeaponAudioEntity::ProjectileFire(eWeaponType weaponType, CPhysical* physical, int32 audioId) {
    plugin::CallMethod<0x4DF060, CAEGlobalWeaponAudioEntity*, eWeaponType, CPhysical*, int32>(this, weaponType, physical, audioId);

    /*
    if (weaponType != WEAPON_ROCKET || weaponType != WEAPON_ROCKET_HS)
        return;

    ???
    auto speed = (SLOBYTE(this->parent.m_pPed) + 1) % 3;
    LOBYTE(this->parent.m_pPed) = speed;
    ???

    if (AEAudioHardware.IsSoundBankLoaded(143, 5)) {
        m_tempSound.Initialise(
            5,
            68,
            this,
            physical->GetPosition(),
            CAEAudioEntity::m_pAudioEventVolumes[audioId] - 8.0f,
            3.0f,
            1.08f + speed,
            1.0f,
            0,
            SOUND_LIFESPAN_TIED_TO_PHYSICAL_ENTITY,
            0.02f,
            0
        );
        m_tempSound.RegisterWithPhysicalEntity(physical);
        AESoundManager.RequestNewSound(&m_tempSound);

        if (AEAudioHardware.IsSoundBankLoaded(138, 19)) {
            m_tempSound.Initialise(
                19,
                26,
                this,
                physical->GetPosition(),
                CAEAudioEntity::m_pAudioEventVolumes[audioId],
                3.0f,
                (1.08f + speed) * 1.25f,
                1.0f,
                0,
                SOUND_LIFESPAN_TIED_TO_PHYSICAL_ENTITY,
                0.02f,
                0
            );
            m_tempSound.RegisterWithPhysicalEntity(physical);
            AESoundManager.RequestNewSound(&m_tempSound);
        } else {
            AEAudioHardware.LoadSoundBank(138, 19);
        }
    } else if (!AudioEngine.IsLoadingTuneActive()) {
        AEAudioHardware.LoadSoundBank(143, 5);
    }
    */
}

// 0x4DF210
void CAEGlobalWeaponAudioEntity::ServiceAmbientGunFire() {
    plugin::CallMethod<0x4DF210, CAEGlobalWeaponAudioEntity*>(this);
}

void CAEGlobalWeaponAudioEntity::InjectHooks() {
    using namespace ReversibleHooks;
    Install("CAEGlobalWeaponAudioEntity", "CAEGlobalWeaponAudioEntity", 0x5075B0, &CAEGlobalWeaponAudioEntity::Constructor);
    Install("CAEGlobalWeaponAudioEntity", "UpdateParameters", 0x4DEF90, &CAEGlobalWeaponAudioEntity::UpdateParameters);
    Install("CAEGlobalWeaponAudioEntity", "AddAudioEvent", 0x4DFAA0, &CAEGlobalWeaponAudioEntity::AddAudioEvent);
    // Install("CAEGlobalWeaponAudioEntity", "ProjectileFire", 0x4DF060, &CAEGlobalWeaponAudioEntity::ProjectileFire);
    // Install("CAEGlobalWeaponAudioEntity", "ServiceAmbientGunFire", 0x4DF210, &CAEGlobalWeaponAudioEntity::ServiceAmbientGunFire);
}

CAEGlobalWeaponAudioEntity* CAEGlobalWeaponAudioEntity::Constructor() {
    this->CAEGlobalWeaponAudioEntity::CAEGlobalWeaponAudioEntity();
    return this;
}