

#include "classinfo/dynamic.hpp"
#include "common.hpp"

namespace client_classes
{

boost::unordered_flat_map<std::string, int *> classid_mapping{};

dynamic::dynamic()
{
    classid_mapping["CTETFParticleEffect"]                   = &CTETFParticleEffect;
    classid_mapping["CTETFExplosion"]                        = &CTETFExplosion;
    classid_mapping["CTETFBlood"]                            = &CTETFBlood;
    classid_mapping["CTFTankBoss"]                           = &CTFTankBoss;
    classid_mapping["CTFBaseBoss"]                           = &CTFBaseBoss;
    classid_mapping["CBossAlpha"]                            = &CBossAlpha;
    classid_mapping["CZombie"]                               = &CZombie;
    classid_mapping["CMerasmusDancer"]                       = &CMerasmusDancer;
    classid_mapping["CMerasmus"]                             = &CMerasmus;
    classid_mapping["CHeadlessHatman"]                       = &CHeadlessHatman;
    classid_mapping["CEyeballBoss"]                          = &CEyeballBoss;
    classid_mapping["CTFWeaponSapper"]                       = &CTFWeaponSapper;
    classid_mapping["CTFWeaponBuilder"]                      = &CTFWeaponBuilder;
    classid_mapping["C_TFWeaponBuilder"]                     = &C_TFWeaponBuilder;
    classid_mapping["CTFTeam"]                               = &CTFTeam;
    classid_mapping["CTFTauntProp"]                          = &CTFTauntProp;
    classid_mapping["CTFProjectile_Rocket"]                  = &CTFProjectile_Rocket;
    classid_mapping["CTFProjectile_Flare"]                   = &CTFProjectile_Flare;
    classid_mapping["CTFProjectile_EnergyBall"]              = &CTFProjectile_EnergyBall;
    classid_mapping["CTFProjectile_GrapplingHook"]           = &CTFProjectile_GrapplingHook;
    classid_mapping["CTFProjectile_HealingBolt"]             = &CTFProjectile_HealingBolt;
    classid_mapping["CTFProjectile_Arrow"]                   = &CTFProjectile_Arrow;
    classid_mapping["CTFPlayerResource"]                     = &CTFPlayerResource;
    classid_mapping["CTFPlayer"]                             = &CTFPlayer;
    classid_mapping["CTFRagdoll"]                            = &CTFRagdoll;
    classid_mapping["CTEPlayerAnimEvent"]                    = &CTEPlayerAnimEvent;
    classid_mapping["CTFPasstimeLogic"]                      = &CTFPasstimeLogic;
    classid_mapping["CPasstimeBall"]                         = &CPasstimeBall;
    classid_mapping["CTFObjectiveResource"]                  = &CTFObjectiveResource;
    classid_mapping["CTFGlow"]                               = &CTFGlow;
    classid_mapping["CTEFireBullets"]                        = &CTEFireBullets;
    classid_mapping["CTFBuffBanner"]                         = &CTFBuffBanner;
    classid_mapping["CTFAmmoPack"]                           = &CTFAmmoPack;
    classid_mapping["CObjectTeleporter"]                     = &CObjectTeleporter;
    classid_mapping["CObjectSentrygun"]                      = &CObjectSentrygun;
    classid_mapping["CTFProjectile_SentryRocket"]            = &CTFProjectile_SentryRocket;
    classid_mapping["CObjectSapper"]                         = &CObjectSapper;
    classid_mapping["CObjectCartDispenser"]                  = &CObjectCartDispenser;
    classid_mapping["CObjectDispenser"]                      = &CObjectDispenser;
    classid_mapping["CMonsterResource"]                      = &CMonsterResource;
    classid_mapping["CFuncRespawnRoomVisualizer"]            = &CFuncRespawnRoomVisualizer;
    classid_mapping["CFuncRespawnRoom"]                      = &CFuncRespawnRoom;
    classid_mapping["CFuncPasstimeGoal"]                     = &CFuncPasstimeGoal;
    classid_mapping["CFuncForceField"]                       = &CFuncForceField;
    classid_mapping["CCaptureZone"]                          = &CCaptureZone;
    classid_mapping["CCurrencyPack"]                         = &CCurrencyPack;
    classid_mapping["CBaseObject"]                           = &CBaseObject;
    classid_mapping["CTFBotHintEngineerNest"]                = &CTFBotHintEngineerNest;
    classid_mapping["CBotNPCMinion"]                         = &CBotNPCMinion;
    classid_mapping["CBotNPC"]                               = &CBotNPC;
    classid_mapping["CRagdollPropAttached"]                  = &CRagdollPropAttached;
    classid_mapping["CRagdollProp"]                          = &CRagdollProp;
    classid_mapping["NextBotCombatCharacter"]                = &NextBotCombatCharacter;
    classid_mapping["CWaterBullet"]                          = &CWaterBullet;
    classid_mapping["CFuncMonitor"]                          = &CFuncMonitor;
    classid_mapping["CWorld"]                                = &CWorld;
    classid_mapping["CWaterLODControl"]                      = &CWaterLODControl;
    classid_mapping["CVGuiScreen"]                           = &CVGuiScreen;
    classid_mapping["CPropJeep"]                             = &CPropJeep;
    classid_mapping["CPropVehicleChoreoGeneric"]             = &CPropVehicleChoreoGeneric;
    classid_mapping["CTEWorldDecal"]                         = &CTEWorldDecal;
    classid_mapping["CTESpriteSpray"]                        = &CTESpriteSpray;
    classid_mapping["CTESprite"]                             = &CTESprite;
    classid_mapping["CTESparks"]                             = &CTESparks;
    classid_mapping["CTESmoke"]                              = &CTESmoke;
    classid_mapping["CTEShowLine"]                           = &CTEShowLine;
    classid_mapping["CTEProjectedDecal"]                     = &CTEProjectedDecal;
    classid_mapping["CTEPlayerDecal"]                        = &CTEPlayerDecal;
    classid_mapping["CTEPhysicsProp"]                        = &CTEPhysicsProp;
    classid_mapping["CTEParticleSystem"]                     = &CTEParticleSystem;
    classid_mapping["CTEMuzzleFlash"]                        = &CTEMuzzleFlash;
    classid_mapping["CTELargeFunnel"]                        = &CTELargeFunnel;
    classid_mapping["CTEKillPlayerAttachments"]              = &CTEKillPlayerAttachments;
    classid_mapping["CTEImpact"]                             = &CTEImpact;
    classid_mapping["CTEGlowSprite"]                         = &CTEGlowSprite;
    classid_mapping["CTEShatterSurface"]                     = &CTEShatterSurface;
    classid_mapping["CTEFootprintDecal"]                     = &CTEFootprintDecal;
    classid_mapping["CTEFizz"]                               = &CTEFizz;
    classid_mapping["CTEExplosion"]                          = &CTEExplosion;
    classid_mapping["CTEEnergySplash"]                       = &CTEEnergySplash;
    classid_mapping["CTEEffectDispatch"]                     = &CTEEffectDispatch;
    classid_mapping["CTEDynamicLight"]                       = &CTEDynamicLight;
    classid_mapping["CTEDecal"]                              = &CTEDecal;
    classid_mapping["CTEClientProjectile"]                   = &CTEClientProjectile;
    classid_mapping["CTEBubbleTrail"]                        = &CTEBubbleTrail;
    classid_mapping["CTEBubbles"]                            = &CTEBubbles;
    classid_mapping["CTEBSPDecal"]                           = &CTEBSPDecal;
    classid_mapping["CTEBreakModel"]                         = &CTEBreakModel;
    classid_mapping["CTEBloodStream"]                        = &CTEBloodStream;
    classid_mapping["CTEBloodSprite"]                        = &CTEBloodSprite;
    classid_mapping["CTEBeamSpline"]                         = &CTEBeamSpline;
    classid_mapping["CTEBeamRingPoint"]                      = &CTEBeamRingPoint;
    classid_mapping["CTEBeamRing"]                           = &CTEBeamRing;
    classid_mapping["CTEBeamPoints"]                         = &CTEBeamPoints;
    classid_mapping["CTEBeamLaser"]                          = &CTEBeamLaser;
    classid_mapping["CTEBeamFollow"]                         = &CTEBeamFollow;
    classid_mapping["CTEBeamEnts"]                           = &CTEBeamEnts;
    classid_mapping["CTEBeamEntPoint"]                       = &CTEBeamEntPoint;
    classid_mapping["CTEBaseBeam"]                           = &CTEBaseBeam;
    classid_mapping["CTEArmorRicochet"]                      = &CTEArmorRicochet;
    classid_mapping["CTEMetalSparks"]                        = &CTEMetalSparks;
    classid_mapping["CTest_ProxyToggle_Networkable"]         = &CTest_ProxyToggle_Networkable;
    classid_mapping["CTestTraceline"]                        = &CTestTraceline;
    classid_mapping["CTesla"]                                = &CTesla;
    classid_mapping["CTeamTrainWatcher"]                     = &CTeamTrainWatcher;
    classid_mapping["CBaseTeamObjectiveResource"]            = &CBaseTeamObjectiveResource;
    classid_mapping["CTeam"]                                 = &CTeam;
    classid_mapping["CSun"]                                  = &CSun;
    classid_mapping["CSteamJet"]                             = &CSteamJet;
    classid_mapping["CParticlePerformanceMonitor"]           = &CParticlePerformanceMonitor;
    classid_mapping["CSpotlightEnd"]                         = &CSpotlightEnd;
    classid_mapping["DustTrail"]                             = &DustTrail;
    classid_mapping["CFireTrail"]                            = &CFireTrail;
    classid_mapping["SporeTrail"]                            = &SporeTrail;
    classid_mapping["SporeExplosion"]                        = &SporeExplosion;
    classid_mapping["RocketTrail"]                           = &RocketTrail;
    classid_mapping["SmokeTrail"]                            = &SmokeTrail;
    classid_mapping["CSmokeStack"]                           = &CSmokeStack;
    classid_mapping["CSlideshowDisplay"]                     = &CSlideshowDisplay;
    classid_mapping["CShadowControl"]                        = &CShadowControl;
    classid_mapping["CSceneEntity"]                          = &CSceneEntity;
    classid_mapping["CRopeKeyframe"]                         = &CRopeKeyframe;
    classid_mapping["CRagdollManager"]                       = &CRagdollManager;
    classid_mapping["CPropVehicleDriveable"]                 = &CPropVehicleDriveable;
    classid_mapping["CPhysicsPropMultiplayer"]               = &CPhysicsPropMultiplayer;
    classid_mapping["CPhysBoxMultiplayer"]                   = &CPhysBoxMultiplayer;
    classid_mapping["CBasePropDoor"]                         = &CBasePropDoor;
    classid_mapping["CDynamicProp"]                          = &CDynamicProp;
    classid_mapping["CPointWorldText"]                       = &CPointWorldText;
    classid_mapping["CPointCommentaryNode"]                  = &CPointCommentaryNode;
    classid_mapping["CPointCamera"]                          = &CPointCamera;
    classid_mapping["CPlayerResource"]                       = &CPlayerResource;
    classid_mapping["CPlasma"]                               = &CPlasma;
    classid_mapping["CPhysMagnet"]                           = &CPhysMagnet;
    classid_mapping["CPhysicsProp"]                          = &CPhysicsProp;
    classid_mapping["CPhysBox"]                              = &CPhysBox;
    classid_mapping["CParticleSystem"]                       = &CParticleSystem;
    classid_mapping["ParticleSmokeGrenade"]                  = &ParticleSmokeGrenade;
    classid_mapping["CParticleFire"]                         = &CParticleFire;
    classid_mapping["MovieExplosion"]                        = &MovieExplosion;
    classid_mapping["CMaterialModifyControl"]                = &CMaterialModifyControl;
    classid_mapping["CLightGlow"]                            = &CLightGlow;
    classid_mapping["CInfoOverlayAccessor"]                  = &CInfoOverlayAccessor;
    classid_mapping["CTEGaussExplosion"]                     = &CTEGaussExplosion;
    classid_mapping["CFuncTrackTrain"]                       = &CFuncTrackTrain;
    classid_mapping["CFuncSmokeVolume"]                      = &CFuncSmokeVolume;
    classid_mapping["CFuncRotating"]                         = &CFuncRotating;
    classid_mapping["CFuncReflectiveGlass"]                  = &CFuncReflectiveGlass;
    classid_mapping["CFuncOccluder"]                         = &CFuncOccluder;
    classid_mapping["CFunc_LOD"]                             = &CFunc_LOD;
    classid_mapping["CTEDust"]                               = &CTEDust;
    classid_mapping["CFunc_Dust"]                            = &CFunc_Dust;
    classid_mapping["CFuncConveyor"]                         = &CFuncConveyor;
    classid_mapping["CBreakableSurface"]                     = &CBreakableSurface;
    classid_mapping["CFuncAreaPortalWindow"]                 = &CFuncAreaPortalWindow;
    classid_mapping["CFish"]                                 = &CFish;
    classid_mapping["CEntityFlame"]                          = &CEntityFlame;
    classid_mapping["CFireSmoke"]                            = &CFireSmoke;
    classid_mapping["CEnvTonemapController"]                 = &CEnvTonemapController;
    classid_mapping["CEnvScreenEffect"]                      = &CEnvScreenEffect;
    classid_mapping["CEnvScreenOverlay"]                     = &CEnvScreenOverlay;
    classid_mapping["CEnvProjectedTexture"]                  = &CEnvProjectedTexture;
    classid_mapping["CEnvParticleScript"]                    = &CEnvParticleScript;
    classid_mapping["CFogController"]                        = &CFogController;
    classid_mapping["CEntityParticleTrail"]                  = &CEntityParticleTrail;
    classid_mapping["CEntityDissolve"]                       = &CEntityDissolve;
    classid_mapping["CEnvQuadraticBeam"]                     = &CEnvQuadraticBeam;
    classid_mapping["CEmbers"]                               = &CEmbers;
    classid_mapping["CEnvWind"]                              = &CEnvWind;
    classid_mapping["CPrecipitation"]                        = &CPrecipitation;
    classid_mapping["CDynamicLight"]                         = &CDynamicLight;
    classid_mapping["CColorCorrectionVolume"]                = &CColorCorrectionVolume;
    classid_mapping["CColorCorrection"]                      = &CColorCorrection;
    classid_mapping["CBreakableProp"]                        = &CBreakableProp;
    classid_mapping["CBaseTempEntity"]                       = &CBaseTempEntity;
    classid_mapping["CBasePlayer"]                           = &CBasePlayer;
    classid_mapping["CBaseFlex"]                             = &CBaseFlex;
    classid_mapping["CBaseEntity"]                           = &CBaseEntity;
    classid_mapping["CBaseDoor"]                             = &CBaseDoor;
    classid_mapping["CBaseCombatCharacter"]                  = &CBaseCombatCharacter;
    classid_mapping["CBaseAnimatingOverlay"]                 = &CBaseAnimatingOverlay;
    classid_mapping["CBoneFollower"]                         = &CBoneFollower;
    classid_mapping["CBaseAnimating"]                        = &CBaseAnimating;
    classid_mapping["CInfoLightingRelative"]                 = &CInfoLightingRelative;
    classid_mapping["CAI_BaseNPC"]                           = &CAI_BaseNPC;
    classid_mapping["CWeaponIFMSteadyCam"]                   = &CWeaponIFMSteadyCam;
    classid_mapping["CWeaponIFMBaseCamera"]                  = &CWeaponIFMBaseCamera;
    classid_mapping["CWeaponIFMBase"]                        = &CWeaponIFMBase;
    classid_mapping["CTFWearableRazorback"]                  = &CTFWearableRazorback;
    classid_mapping["CTFWearableDemoShield"]                 = &CTFWearableDemoShield;
    classid_mapping["CTFWearableLevelableItem"]              = &CTFWearableLevelableItem;
    classid_mapping["CTFWearableCampaignItem"]               = &CTFWearableCampaignItem;
    classid_mapping["CTFWearableRobotArm"]                   = &CTFWearableRobotArm;
    classid_mapping["CTFRobotArm"]                           = &CTFRobotArm;
    classid_mapping["CTFWrench"]                             = &CTFWrench;
    classid_mapping["CTFProjectile_ThrowableBreadMonster"]   = &CTFProjectile_ThrowableBreadMonster;
    classid_mapping["CTFProjectile_ThrowableBrick"]          = &CTFProjectile_ThrowableBrick;
    classid_mapping["CTFProjectile_ThrowableRepel"]          = &CTFProjectile_ThrowableRepel;
    classid_mapping["CTFProjectile_Throwable"]               = &CTFProjectile_Throwable;
    classid_mapping["CTFThrowable"]                          = &CTFThrowable;
    classid_mapping["CTFSyringeGun"]                         = &CTFSyringeGun;
    classid_mapping["CTFKatana"]                             = &CTFKatana;
    classid_mapping["CTFSword"]                              = &CTFSword;
    classid_mapping["CSniperDot"]                            = &CSniperDot;
    classid_mapping["CTFSniperRifleClassic"]                 = &CTFSniperRifleClassic;
    classid_mapping["CTFSniperRifleDecap"]                   = &CTFSniperRifleDecap;
    classid_mapping["CTFSniperRifle"]                        = &CTFSniperRifle;
    classid_mapping["CTFChargedSMG"]                         = &CTFChargedSMG;
    classid_mapping["CTFSMG"]                                = &CTFSMG;
    classid_mapping["CTFSlap"]                               = &CTFSlap;
    classid_mapping["CTFShovel"]                             = &CTFShovel;
    classid_mapping["CTFShotgunBuildingRescue"]              = &CTFShotgunBuildingRescue;
    classid_mapping["CTFPEPBrawlerBlaster"]                  = &CTFPEPBrawlerBlaster;
    classid_mapping["CTFSodaPopper"]                         = &CTFSodaPopper;
    classid_mapping["CTFShotgun_Revenge"]                    = &CTFShotgun_Revenge;
    classid_mapping["CTFScatterGun"]                         = &CTFScatterGun;
    classid_mapping["CTFShotgun_Pyro"]                       = &CTFShotgun_Pyro;
    classid_mapping["CTFShotgun_HWG"]                        = &CTFShotgun_HWG;
    classid_mapping["CTFShotgun_Soldier"]                    = &CTFShotgun_Soldier;
    classid_mapping["CTFShotgun"]                            = &CTFShotgun;
    classid_mapping["CTFRocketPack"]                         = &CTFRocketPack;
    classid_mapping["CTFCrossbow"]                           = &CTFCrossbow;
    classid_mapping["CTFRocketLauncher_Mortar"]              = &CTFRocketLauncher_Mortar;
    classid_mapping["CTFRocketLauncher_AirStrike"]           = &CTFRocketLauncher_AirStrike;
    classid_mapping["CTFRocketLauncher_DirectHit"]           = &CTFRocketLauncher_DirectHit;
    classid_mapping["CTFRocketLauncher"]                     = &CTFRocketLauncher;
    classid_mapping["CTFRevolver"]                           = &CTFRevolver;
    classid_mapping["CTFDRGPomson"]                          = &CTFDRGPomson;
    classid_mapping["CTFRaygun"]                             = &CTFRaygun;
    classid_mapping["CTFPistol_ScoutSecondary"]              = &CTFPistol_ScoutSecondary;
    classid_mapping["CTFPistol_ScoutPrimary"]                = &CTFPistol_ScoutPrimary;
    classid_mapping["CTFPistol_Scout"]                       = &CTFPistol_Scout;
    classid_mapping["CTFPistol"]                             = &CTFPistol;
    classid_mapping["CTFPipebombLauncher"]                   = &CTFPipebombLauncher;
    classid_mapping["CTFWeaponPDA_Spy"]                      = &CTFWeaponPDA_Spy;
    classid_mapping["CTFWeaponPDA_Engineer_Destroy"]         = &CTFWeaponPDA_Engineer_Destroy;
    classid_mapping["CTFWeaponPDA_Engineer_Build"]           = &CTFWeaponPDA_Engineer_Build;
    classid_mapping["CTFWeaponPDAExpansion_Teleporter"]      = &CTFWeaponPDAExpansion_Teleporter;
    classid_mapping["CTFWeaponPDAExpansion_Dispenser"]       = &CTFWeaponPDAExpansion_Dispenser;
    classid_mapping["CTFWeaponPDA"]                          = &CTFWeaponPDA;
    classid_mapping["CPasstimeGun"]                          = &CPasstimeGun;
    classid_mapping["CTFParticleCannon"]                     = &CTFParticleCannon;
    classid_mapping["CTFParachute_Secondary"]                = &CTFParachute_Secondary;
    classid_mapping["CTFParachute_Primary"]                  = &CTFParachute_Primary;
    classid_mapping["CTFParachute"]                          = &CTFParachute;
    classid_mapping["CTFMinigun"]                            = &CTFMinigun;
    classid_mapping["CTFMedigunShield"]                      = &CTFMedigunShield;
    classid_mapping["CWeaponMedigun"]                        = &CWeaponMedigun;
    classid_mapping["CTFProjectile_MechanicalArmOrb"]        = &CTFProjectile_MechanicalArmOrb;
    classid_mapping["CTFMechanicalArm"]                      = &CTFMechanicalArm;
    classid_mapping["CTFLunchBox_Drink"]                     = &CTFLunchBox_Drink;
    classid_mapping["CTFLunchBox"]                           = &CTFLunchBox;
    classid_mapping["CLaserDot"]                             = &CLaserDot;
    classid_mapping["CTFLaserPointer"]                       = &CTFLaserPointer;
    classid_mapping["CTFKnife"]                              = &CTFKnife;
    classid_mapping["CTFGasManager"]                         = &CTFGasManager;
    classid_mapping["CTFProjectile_JarGas"]                  = &CTFProjectile_JarGas;
    classid_mapping["CTFJarGas"]                             = &CTFJarGas;
    classid_mapping["CTFProjectile_Cleaver"]                 = &CTFProjectile_Cleaver;
    classid_mapping["CTFProjectile_JarMilk"]                 = &CTFProjectile_JarMilk;
    classid_mapping["CTFProjectile_Jar"]                     = &CTFProjectile_Jar;
    classid_mapping["CTFCleaver"]                            = &CTFCleaver;
    classid_mapping["CTFJarMilk"]                            = &CTFJarMilk;
    classid_mapping["CTFJar"]                                = &CTFJar;
    classid_mapping["CTFWeaponInvis"]                        = &CTFWeaponInvis;
    classid_mapping["CTFGrenadePipebombProjectile"]          = &CTFGrenadePipebombProjectile;
    classid_mapping["CTFCannon"]                             = &CTFCannon;
    classid_mapping["CTFGrenadeLauncher"]                    = &CTFGrenadeLauncher;
    classid_mapping["CTFGrapplingHook"]                      = &CTFGrapplingHook;
    classid_mapping["CTFFlareGun_Revenge"]                   = &CTFFlareGun_Revenge;
    classid_mapping["CTFFlareGun"]                           = &CTFFlareGun;
    classid_mapping["CTFFlameRocket"]                        = &CTFFlameRocket;
    classid_mapping["CTFFlameThrower"]                       = &CTFFlameThrower;
    classid_mapping["CTFFists"]                              = &CTFFists;
    classid_mapping["CTFFireAxe"]                            = &CTFFireAxe;
    classid_mapping["CTFWeaponFlameBall"]                    = &CTFWeaponFlameBall;
    classid_mapping["CTFCompoundBow"]                        = &CTFCompoundBow;
    classid_mapping["CTFClub"]                               = &CTFClub;
    classid_mapping["CTFBuffItem"]                           = &CTFBuffItem;
    classid_mapping["CTFStickBomb"]                          = &CTFStickBomb;
    classid_mapping["CTFBreakableSign"]                      = &CTFBreakableSign;
    classid_mapping["CTFBottle"]                             = &CTFBottle;
    classid_mapping["CTFBreakableMelee"]                     = &CTFBreakableMelee;
    classid_mapping["CTFBonesaw"]                            = &CTFBonesaw;
    classid_mapping["CTFBall_Ornament"]                      = &CTFBall_Ornament;
    classid_mapping["CTFStunBall"]                           = &CTFStunBall;
    classid_mapping["CTFBat_Giftwrap"]                       = &CTFBat_Giftwrap;
    classid_mapping["CTFBat_Wood"]                           = &CTFBat_Wood;
    classid_mapping["CTFBat_Fish"]                           = &CTFBat_Fish;
    classid_mapping["CTFBat"]                                = &CTFBat;
    classid_mapping["CTFBaseRocket"]                         = &CTFBaseRocket;
    classid_mapping["CTFWeaponBaseMerasmusGrenade"]          = &CTFWeaponBaseMerasmusGrenade;
    classid_mapping["CTFWeaponBaseMelee"]                    = &CTFWeaponBaseMelee;
    classid_mapping["CTFWeaponBaseGun"]                      = &CTFWeaponBaseGun;
    classid_mapping["CTFWeaponBaseGrenadeProj"]              = &CTFWeaponBaseGrenadeProj;
    classid_mapping["CTFWeaponBase"]                         = &CTFWeaponBase;
    classid_mapping["CTFViewModel"]                          = &CTFViewModel;
    classid_mapping["CRobotDispenser"]                       = &CRobotDispenser;
    classid_mapping["CTFRobotDestruction_Robot"]             = &CTFRobotDestruction_Robot;
    classid_mapping["CTFReviveMarker"]                       = &CTFReviveMarker;
    classid_mapping["CTFPumpkinBomb"]                        = &CTFPumpkinBomb;
    classid_mapping["CTFProjectile_EnergyRing"]              = &CTFProjectile_EnergyRing;
    classid_mapping["CTFProjectile_BallOfFire"]              = &CTFProjectile_BallOfFire;
    classid_mapping["CTFBaseProjectile"]                     = &CTFBaseProjectile;
    classid_mapping["CTFPointManager"]                       = &CTFPointManager;
    classid_mapping["CBaseObjectUpgrade"]                    = &CBaseObjectUpgrade;
    classid_mapping["CMannVsMachineStats"]                   = &CMannVsMachineStats;
    classid_mapping["CTFRobotDestructionLogic"]              = &CTFRobotDestructionLogic;
    classid_mapping["CTFRobotDestruction_RobotGroup"]        = &CTFRobotDestruction_RobotGroup;
    classid_mapping["CTFRobotDestruction_RobotSpawn"]        = &CTFRobotDestruction_RobotSpawn;
    classid_mapping["CTFPlayerDestructionLogic"]             = &CTFPlayerDestructionLogic;
    classid_mapping["CPlayerDestructionDispenser"]           = &CPlayerDestructionDispenser;
    classid_mapping["CTFMinigameLogic"]                      = &CTFMinigameLogic;
    classid_mapping["CTFHalloweenMinigame_FallingPlatforms"] = &CTFHalloweenMinigame_FallingPlatforms;
    classid_mapping["CTFHalloweenMinigame"]                  = &CTFHalloweenMinigame;
    classid_mapping["CTFMiniGame"]                           = &CTFMiniGame;
    classid_mapping["CTFWearableVM"]                         = &CTFWearableVM;
    classid_mapping["CTFWearable"]                           = &CTFWearable;
    classid_mapping["CTFPowerupBottle"]                      = &CTFPowerupBottle;
    classid_mapping["CTFItem"]                               = &CTFItem;
    classid_mapping["CHalloweenSoulPack"]                    = &CHalloweenSoulPack;
    classid_mapping["CTFGenericBomb"]                        = &CTFGenericBomb;
    classid_mapping["CBonusRoundLogic"]                      = &CBonusRoundLogic;
    classid_mapping["CTFGameRulesProxy"]                     = &CTFGameRulesProxy;
    classid_mapping["CTFFlameManager"]                       = &CTFFlameManager;
    classid_mapping["CTFDroppedWeapon"]                      = &CTFDroppedWeapon;
    classid_mapping["CTFProjectile_SpellKartBats"]           = &CTFProjectile_SpellKartBats;
    classid_mapping["CTFProjectile_SpellKartOrb"]            = &CTFProjectile_SpellKartOrb;
    classid_mapping["CTFHellZap"]                            = &CTFHellZap;
    classid_mapping["CTFProjectile_SpellLightningOrb"]       = &CTFProjectile_SpellLightningOrb;
    classid_mapping["CTFProjectile_SpellTransposeTeleport"]  = &CTFProjectile_SpellTransposeTeleport;
    classid_mapping["CTFProjectile_SpellMeteorShower"]       = &CTFProjectile_SpellMeteorShower;
    classid_mapping["CTFProjectile_SpellSpawnBoss"]          = &CTFProjectile_SpellSpawnBoss;
    classid_mapping["CTFProjectile_SpellMirv"]               = &CTFProjectile_SpellMirv;
    classid_mapping["CTFProjectile_SpellPumpkin"]            = &CTFProjectile_SpellPumpkin;
    classid_mapping["CTFProjectile_SpellSpawnHorde"]         = &CTFProjectile_SpellSpawnHorde;
    classid_mapping["CTFProjectile_SpellSpawnZombie"]        = &CTFProjectile_SpellSpawnZombie;
    classid_mapping["CTFProjectile_SpellBats"]               = &CTFProjectile_SpellBats;
    classid_mapping["CTFProjectile_SpellFireball"]           = &CTFProjectile_SpellFireball;
    classid_mapping["CTFSpellBook"]                          = &CTFSpellBook;
    classid_mapping["CHightower_TeleportVortex"]             = &CHightower_TeleportVortex;
    classid_mapping["CTeleportVortex"]                       = &CTeleportVortex;
    classid_mapping["CHalloweenGiftPickup"]                  = &CHalloweenGiftPickup;
    classid_mapping["CBonusDuckPickup"]                      = &CBonusDuckPickup;
    classid_mapping["CHalloweenPickup"]                      = &CHalloweenPickup;
    classid_mapping["CCaptureFlagReturnIcon"]                = &CCaptureFlagReturnIcon;
    classid_mapping["CCaptureFlag"]                          = &CCaptureFlag;
    classid_mapping["CBonusPack"]                            = &CBonusPack;
    classid_mapping["CHandleTest"]                           = &CHandleTest;
    classid_mapping["CTeamRoundTimer"]                       = &CTeamRoundTimer;
    classid_mapping["CTeamplayRoundBasedRulesProxy"]         = &CTeamplayRoundBasedRulesProxy;
    classid_mapping["CSpriteTrail"]                          = &CSpriteTrail;
    classid_mapping["CSpriteOriented"]                       = &CSpriteOriented;
    classid_mapping["CSprite"]                               = &CSprite;
    classid_mapping["CPoseController"]                       = &CPoseController;
    classid_mapping["CGameRulesProxy"]                       = &CGameRulesProxy;
    classid_mapping["CInfoLadderDismount"]                   = &CInfoLadderDismount;
    classid_mapping["CFuncLadder"]                           = &CFuncLadder;
    classid_mapping["CEnvDetailController"]                  = &CEnvDetailController;
    classid_mapping["CTFWearableItem"]                       = &CTFWearableItem;
    classid_mapping["CEconWearable"]                         = &CEconWearable;
    classid_mapping["CBaseAttributableItem"]                 = &CBaseAttributableItem;
    classid_mapping["CEconEntity"]                           = &CEconEntity;
    classid_mapping["CBeam"]                                 = &CBeam;
    classid_mapping["CBaseViewModel"]                        = &CBaseViewModel;
    classid_mapping["CBaseProjectile"]                       = &CBaseProjectile;
    classid_mapping["CBaseParticleEntity"]                   = &CBaseParticleEntity;
    classid_mapping["CBaseGrenade"]                          = &CBaseGrenade;
    classid_mapping["CBaseCombatWeapon"]                     = &CBaseCombatWeapon;
    classid_mapping["CVoteController"]                       = &CVoteController;
    classid_mapping["CWeaponSpawner"]                        = &CWeaponSpawner;
    classid_mapping["CCSPlayerResource"]                     = &CCSPlayerResource;
    classid_mapping["CCSPlayer"]                             = &CCSPlayer;
    classid_mapping["CHL2MP_Player"]                         = &CHL2MP_Player;
    classid_mapping["CWeaponStunStick"]                      = &CWeaponStunStick;
    classid_mapping["CWeaponSMG1"]                           = &CWeaponSMG1;
    classid_mapping["CWeapon_SLAM"]                          = &CWeapon_SLAM;
    classid_mapping["CWeaponShotgun"]                        = &CWeaponShotgun;
    classid_mapping["CWeaponRPG"]                            = &CWeaponRPG;
    classid_mapping["CWeaponPistol"]                         = &CWeaponPistol;
    classid_mapping["CWeaponPhysCannon"]                     = &CWeaponPhysCannon;
    classid_mapping["CWeaponAnnabelle"]                      = &CWeaponAnnabelle;
    classid_mapping["CWeaponBinoculars"]                     = &CWeaponBinoculars;
    classid_mapping["CWeaponBugBait"]                        = &CWeaponBugBait;
    classid_mapping["CWeaponHL2MPBase"]                      = &CWeaponHL2MPBase;
    classid_mapping["CWeaponFrag"]                           = &CWeaponFrag;
    classid_mapping["CWeaponCrowbar"]                        = &CWeaponCrowbar;
    classid_mapping["CWeaponCrossbow"]                       = &CWeaponCrossbow;
    classid_mapping["CWeaponAR2"]                            = &CWeaponAR2;
    classid_mapping["CWeapon357"]                            = &CWeapon357;
    classid_mapping["CWeaponCitizenSuitcase"]                = &CWeaponCitizenSuitcase;
    classid_mapping["CWeaponCitizenPackage"]                 = &CWeaponCitizenPackage;
    classid_mapping["CWeaponAlyxGun"]                        = &CWeaponAlyxGun;
}

void dynamic::Populate()
{
    ClientClass *cc = g_IBaseClient->GetAllClasses();
    while (cc)
    {
        std::string name(cc->GetName());
        if (classid_mapping.find(name) != classid_mapping.end())
            *classid_mapping[name] = cc->m_ClassID;
        cc = cc->m_pNext;
    }
}

dynamic dynamic_list;

} // namespace client_classes
