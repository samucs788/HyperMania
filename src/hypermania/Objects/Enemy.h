// WARNING: this file is heavily auto-generated, only modify if you know what you are doing
#include "GameAPI/Game.h"
// .h includes start on line 3
#include "Boilerplate/MSZ/HeavyMystic.h"
#include "Boilerplate/MSZ/DBTower.h"
#include "Boilerplate/MSZ/UberCaterkiller.h"
#include "Boilerplate/HCZ/LaundroMobile.h"
#include "Boilerplate/SSZ/GigaMetal.h"
#include "Boilerplate/SSZ/MetalSonic.h"
#include "Boilerplate/SSZ/HotaruHiWatt.h"
#include "Boilerplate/PGZ/HeavyShinobi.h"
#include "Boilerplate/PGZ/Shiversaw.h"
#include "Boilerplate/FBZ/BigSqueeze.h"
#include "Boilerplate/SPZ/WeatherMobile.h"
#include "Boilerplate/CPZ/AmoebaDroid.h"
#include "Boilerplate/GHZ/DERobot.h"
#include "Boilerplate/GHZ/DDWrecker.h"


#include "Boilerplate/TMZ/FlasherMKII.h"
#include "Boilerplate/TMZ/TurboTurtle.h"
#include "Boilerplate/TMZ/SentryBug.h"
#include "Boilerplate/TMZ/BallHog.h"
#include "Boilerplate/MMZ/PohBee.h"
#include "Boilerplate/MMZ/Scarab.h"
#include "Boilerplate/MMZ/MechaBu.h"
#include "Boilerplate/LRZ/Fireworm.h"
#include "Boilerplate/LRZ/Rexon.h"
#include "Boilerplate/LRZ/Toxomister.h"
#include "Boilerplate/OOZ/Octus.h"
#include "Boilerplate/OOZ/Sol.h"
#include "Boilerplate/OOZ/Aquis.h"
#include "Boilerplate/MSZ/Rattlekiller.h"
#include "Boilerplate/MSZ/RollerMKII.h"
#include "Boilerplate/MSZ/Vultron.h"
#include "Boilerplate/MSZ/Bumpalo.h"
#include "Boilerplate/MSZ/Armadiloid.h"
#include "Boilerplate/MSZ/Cactula.h"
#include "Boilerplate/MSZ/Hatterkiller.h"
#include "Boilerplate/HCZ/TurboSpiker.h"
#include "Boilerplate/HCZ/Buggernaut.h"
#include "Boilerplate/HCZ/MegaChopper.h"
#include "Boilerplate/HCZ/Jawz.h"
#include "Boilerplate/HCZ/Jellygnite.h"
#include "Boilerplate/HCZ/Blastoid.h"
#include "Boilerplate/HCZ/Pointdexter.h"
#include "Boilerplate/SSZ/Kabasira.h"
#include "Boilerplate/SSZ/Dango.h"
#include "Boilerplate/SSZ/Kanabun.h"
#include "Boilerplate/SSZ/HotaruMKII.h"
#include "Boilerplate/SSZ/Hotaru.h"
#include "Boilerplate/PGZ/Woodrow.h"
#include "Boilerplate/PGZ/Dragonfly.h"
#include "Boilerplate/PGZ/IceBomba.h"
#include "Boilerplate/PGZ/JuggleSaw.h"
#include "Boilerplate/FBZ/FBZTrash.h"
#include "Boilerplate/FBZ/Technosqueek.h"
#include "Boilerplate/FBZ/Clucker.h"
#include "Boilerplate/FBZ/Blaster.h"
#include "Boilerplate/SPZ/Shutterbug.h"
#include "Boilerplate/SPZ/Canista.h"
#include "Boilerplate/SPZ/Tubinaut.h"
#include "Boilerplate/SPZ/MicDrop.h"
#include "Boilerplate/CPZ/Grabber.h"
#include "Boilerplate/CPZ/Spiny.h"
#include "Boilerplate/CPZ/CaterkillerJr.h"
#include "Boilerplate/CPZ/Bubbler.h"
#include "Boilerplate/GHZ/Splats.h"
#include "Boilerplate/GHZ/Newtron.h"
#include "Boilerplate/GHZ/Chopper.h"
#include "Boilerplate/GHZ/Crabmeat.h"
#include "Boilerplate/GHZ/Batbrain.h"
#include "Boilerplate/GHZ/Motobug.h"
#include "Boilerplate/GHZ/BuzzBomber.h"

typedef struct {
	RSDK_ENTITY
	StateMachine(state);
} EntityEnemy;





extern int32 AttackableClasses_startidx;
bool32 Generic_CheckVulnerable(Entity* self);
Hitbox* Generic_GetHitbox(Entity* self);
void Generic_OnHit(EntityPlayer* player, Entity* self);
void Generic_BadnikBreak_NoEntity(EntityPlayer* player, Vector2 position, bool32 spawnAnimals);








typedef struct {
	uint16 classID;
	bool32 animal;
	bool32 boss;
	struct { void* func; Hitbox* hitbox; } states[8];
	bool32 (*check_func)(Entity*);
	Hitbox* (*hitbox_func)(Entity*);
	void (*destroy_func)(EntityPlayer*, Entity*); // NOTE -- destroy_func is used as the hit callback for bosses
} EnemyInfo;
extern EnemyInfo EnemyDefs[32];
extern int16 EnemyInfoSlot;

void Generic_BadnikBreak(EntityPlayer* player, Entity* entity, bool32 spawnAnimals);

#define GET_MANIA_FUNC(name) name = Mod.GetPublicFunction(NULL, #name)
#define REGISTER_ENEMY(name) MOD_REGISTER_OBJ_OVERLOAD(name, NULL, NULL, NULL, NULL, NULL, name##_EnemyInfoHook, NULL, NULL, NULL)

// object hooks start after the following line (pattern match)
#define HOOK_ENEMY_OBJECTS \
  OBJ_HEAVYMYSTIC_SETUP; \
  OBJ_DBTOWER_SETUP; \
  OBJ_UBERCATERKILLER_SETUP; \
  OBJ_LAUNDROMOBILE_SETUP; \
  OBJ_METALSONIC_SETUP; \
  OBJ_GIGAMETAL_SETUP; \
  OBJ_HOTARUHIWATT_SETUP; \
  OBJ_HEAVYSHINOBI_SETUP; \
  OBJ_SHIVERSAW_SETUP; \
  REGISTER_ENEMY(BigSqueeze); \
  MOD_REGISTER_OBJECT_HOOK(TVPole); \
  REGISTER_ENEMY(WeatherMobile); \
  REGISTER_ENEMY(AmoebaDroid); \
  REGISTER_ENEMY(DERobot); \
  REGISTER_ENEMY(DDWrecker); \
  \
  \
  REGISTER_ENEMY(FlasherMKII); \
  REGISTER_ENEMY(TurboTurtle); \
  REGISTER_ENEMY(SentryBug); \
  REGISTER_ENEMY(BallHog); \
  REGISTER_ENEMY(PohBee); \
  REGISTER_ENEMY(Scarab); \
  REGISTER_ENEMY(MechaBu); \
  REGISTER_ENEMY(Fireworm); \
  REGISTER_ENEMY(Rexon); \
  REGISTER_ENEMY(Toxomister); \
  REGISTER_ENEMY(Octus); \
  REGISTER_ENEMY(Sol); \
  REGISTER_ENEMY(Aquis); \
  REGISTER_ENEMY(Rattlekiller); \
  REGISTER_ENEMY(RollerMKII); \
  REGISTER_ENEMY(Vultron); \
  REGISTER_ENEMY(Bumpalo); \
  REGISTER_ENEMY(Armadiloid); \
  REGISTER_ENEMY(Cactula); \
  REGISTER_ENEMY(Hatterkiller); \
  REGISTER_ENEMY(TurboSpiker); \
  REGISTER_ENEMY(Buggernaut); \
  REGISTER_ENEMY(MegaChopper); \
  REGISTER_ENEMY(Jawz); \
  REGISTER_ENEMY(Jellygnite); \
  REGISTER_ENEMY(Blastoid); \
  REGISTER_ENEMY(Pointdexter); \
  OBJ_KABASIRA_SETUP; \
  OBJ_DANGO_SETUP; \
  OBJ_KANABUN_SETUP; \
  OBJ_HOTARUMKII_SETUP; \
  OBJ_HOTARU_SETUP; \
  REGISTER_ENEMY(Woodrow); \
  REGISTER_ENEMY(Dragonfly); \
  REGISTER_ENEMY(IceBomba); \
  REGISTER_ENEMY(JuggleSaw); \
  REGISTER_ENEMY(FBZTrash); \
  REGISTER_ENEMY(Technosqueek); \
  REGISTER_ENEMY(Clucker); \
  REGISTER_ENEMY(Blaster); \
  REGISTER_ENEMY(Canista); \
  REGISTER_ENEMY(Tubinaut); \
  REGISTER_ENEMY(Shutterbug); \
  REGISTER_ENEMY(MicDrop); \
  REGISTER_ENEMY(Spiny); \
  REGISTER_ENEMY(Grabber); \
  OBJ_CATERKILLERJR_SETUP; \
  REGISTER_ENEMY(Bubbler); \
  REGISTER_ENEMY(Splats); \
  REGISTER_ENEMY(Newtron); \
  REGISTER_ENEMY(Chopper); \
  REGISTER_ENEMY(Crabmeat); \
  REGISTER_ENEMY(Batbrain); \
  REGISTER_ENEMY(Motobug); \
  OBJ_BUZZBOMBER_SETUP

// function imports start after the following line (pattern match
#define IMPORT_ENEMY_FUNCTIONS \
  GET_MANIA_FUNC(Shiversaw_Hit); \
  GET_MANIA_FUNC(BigSqueeze_StateBoss_Idle); \
  GET_MANIA_FUNC(BigSqueeze_StateBoss_Electrified); \
  GET_MANIA_FUNC(BigSqueeze_HandleWallCollisions); \
  GET_MANIA_FUNC(BigSqueeze_StateBoss_Destroyed); \
  GET_MANIA_FUNC(WeatherMobile_State_EnterEggman); \
  GET_MANIA_FUNC(WeatherMobile_State_HandleMovement); \
  GET_MANIA_FUNC(WeatherMobile_State_WindAttack); \
  GET_MANIA_FUNC(WeatherMobile_State_SunAttack); \
  GET_MANIA_FUNC(AmoebaDroid_State_DropIn); \
  GET_MANIA_FUNC(WeatherMobile_State_EnterEggman); \
  GET_MANIA_FUNC(WeatherMobile_State_Defeated); \
  GET_MANIA_FUNC(WeatherMobile_StateLights_Shine); \
  GET_MANIA_FUNC(WeatherMobile_StateLights_DimAndDissapear); \
  GET_MANIA_FUNC(WeatherMobile_StateCloud_FadeAway); \
  GET_MANIA_FUNC(TVPole_State_ForceRelease); \
  GET_MANIA_FUNC(AmoebaDroid_State_DropIntoPool); \
  GET_MANIA_FUNC(AmoebaDroid_State_SurfaceFromPool); \
  GET_MANIA_FUNC(AmoebaDroid_State_ChooseAttack); \
  GET_MANIA_FUNC(AmoebaDroid_State_ExitPool); \
  GET_MANIA_FUNC(AmoebaDroid_State_BounceAttack); \
  GET_MANIA_FUNC(AmoebaDroid_State_GatherBlobs); \
  GET_MANIA_FUNC(AmoebaDroid_State_SpinBlobs); \
  GET_MANIA_FUNC(AmoebaDroid_State_Destroyed); \
  GET_MANIA_FUNC(DERobot_Hit); \
  GET_MANIA_FUNC(DERobot_State_FallLand); \
  GET_MANIA_FUNC(DERobot_State_Walk); \
  GET_MANIA_FUNC(DERobot_State_ArmAttack); \
  GET_MANIA_FUNC(DDWrecker_Hit); \
  GET_MANIA_FUNC(DDWrecker_StateBall_Vulnerable); \
  GET_MANIA_FUNC(DDWrecker_StateBall_Spiked); \
  GET_MANIA_FUNC(DDWrecker_StateBall_Partnerless); \
  \
  \
  GET_MANIA_FUNC(FlasherMKII_State_Idle); \
  GET_MANIA_FUNC(FlasherMKII_State_Moving); \
  GET_MANIA_FUNC(FlasherMKII_State_WeakFlash); \
  GET_MANIA_FUNC(FlasherMKII_State_StrongFlash); \
  GET_MANIA_FUNC(FlasherMKII_State_FinishedFlashing); \
  GET_MANIA_FUNC(SentryBug_State_ReturnToSlots); \
  GET_MANIA_FUNC(SentryBug_State_NetFlash); \
  GET_MANIA_FUNC(SentryBug_State_NetShrink); \
  GET_MANIA_FUNC(SentryBug_State_NetAppear); \
  GET_MANIA_FUNC(SentryBug_State_DropOrbs); \
  GET_MANIA_FUNC(SentryBug_State_AwaitPlayer); \
  GET_MANIA_FUNC(BallHog_State_DropBomb); \
  GET_MANIA_FUNC(BallHog_State_Land); \
  GET_MANIA_FUNC(BallHog_State_Jump); \
  GET_MANIA_FUNC(BallHog_State_Idle); \
  GET_MANIA_FUNC(MechaBu_State_Falling); \
  GET_MANIA_FUNC(MechaBu_State_Stopped); \
  GET_MANIA_FUNC(MechaBu_State_Moving); \
  GET_MANIA_FUNC(Fireworm_State_FlyAround); \
  GET_MANIA_FUNC(Rexon_State_Hidden); \
  GET_MANIA_FUNC(Rexon_State_Rising); \
  GET_MANIA_FUNC(Rexon_State_Shooting); \
  GET_MANIA_FUNC(Rexon_State_Destroyed); \
  GET_MANIA_FUNC(Rexon_State_Explode); \
  GET_MANIA_FUNC(Toxomister_State_CreateClouds); \
  GET_MANIA_FUNC(Octus_State_Fall); \
  GET_MANIA_FUNC(Octus_State_Shoot); \
  GET_MANIA_FUNC(Octus_State_Jump); \
  GET_MANIA_FUNC(Octus_State_JumpDelay); \
  GET_MANIA_FUNC(Octus_State_CheckPlayerInRange); \
  GET_MANIA_FUNC(Sol_State_ActiveFireball); \
  GET_MANIA_FUNC(Sol_State_NoOrbs); \
  GET_MANIA_FUNC(Sol_State_ShootingOrbs); \
  GET_MANIA_FUNC(Sol_State_Moving); \
  GET_MANIA_FUNC(Aquis_State_Flee); \
  GET_MANIA_FUNC(Aquis_State_Turning); \
  GET_MANIA_FUNC(Aquis_State_Shoot); \
  GET_MANIA_FUNC(Aquis_State_Moving); \
  GET_MANIA_FUNC(Aquis_State_Idle); \
  GET_MANIA_FUNC(RollerMKII_State_Idle); \
  GET_MANIA_FUNC(RollerMKII_State_SpinUp); \
  GET_MANIA_FUNC(Vultron_State_CheckPlayerInRange); \
  GET_MANIA_FUNC(Vultron_State_Hop); \
  GET_MANIA_FUNC(Vultron_State_Dive); \
  GET_MANIA_FUNC(Vultron_State_Flying); \
  GET_MANIA_FUNC(Vultron_State_Rise); \
  GET_MANIA_FUNC(Vultron_State_PrepareDive); \
  GET_MANIA_FUNC(Vultron_State_Targeting); \
  GET_MANIA_FUNC(Bumpalo_State_Falling); \
  GET_MANIA_FUNC(Bumpalo_State_Bumped); \
  GET_MANIA_FUNC(Bumpalo_State_Turning); \
  GET_MANIA_FUNC(Bumpalo_State_Charging); \
  GET_MANIA_FUNC(Bumpalo_State_Idle); \
  GET_MANIA_FUNC(Bumpalo_State_Moving); \
  GET_MANIA_FUNC(Armadiloid_State_Rider); \
  GET_MANIA_FUNC(Cactula_State_DropBomb); \
  GET_MANIA_FUNC(Cactula_State_Rising); \
  GET_MANIA_FUNC(Cactula_State_CheckPlayerInRange); \
  GET_MANIA_FUNC(TurboSpiker_State_FireShell); \
  GET_MANIA_FUNC(TurboSpiker_State_Falling); \
  GET_MANIA_FUNC(TurboSpiker_State_FinishTurning); \
  GET_MANIA_FUNC(TurboSpiker_State_Turning); \
  GET_MANIA_FUNC(TurboSpiker_State_Moving); \
  GET_MANIA_FUNC(TurboSpiker_State_Hidden); \
  GET_MANIA_FUNC(TurboSpiker_State_Idle); \
  GET_MANIA_FUNC(Buggernaut_State_FlyAway); \
  GET_MANIA_FUNC(Buggernaut_State_FlyTowardTarget); \
  GET_MANIA_FUNC(Buggernaut_State_Idle); \
  GET_MANIA_FUNC(MegaChopper_State_OutOfWater); \
  GET_MANIA_FUNC(MegaChopper_State_InWater); \
  GET_MANIA_FUNC(Jawz_State_Triggered); \
  GET_MANIA_FUNC(Jellygnite_State_Swimming); \
  GET_MANIA_FUNC(Jellygnite_State_GrabbedPlayer); \
  GET_MANIA_FUNC(Blastoid_State_Body); \
  GET_MANIA_FUNC(Pointdexter_State_Swimming); \
  GET_MANIA_FUNC(Woodrow_State_Idle); \
  GET_MANIA_FUNC(Woodrow_State_MoveUp); \
  GET_MANIA_FUNC(Woodrow_State_MoveDown); \
  GET_MANIA_FUNC(Dragonfly_State_Move); \
  GET_MANIA_FUNC(IceBomba_State_Flying); \
  GET_MANIA_FUNC(IceBomba_State_Turning); \
  GET_MANIA_FUNC(IceBomba_State_FlyAway); \
  GET_MANIA_FUNC(JuggleSaw_StateCrab_Handle); \
  GET_MANIA_FUNC(JuggleSaw_StateCrab_ThrowSaw); \
  GET_MANIA_FUNC(FBZTrash_State_OrbinautMove); \
  GET_MANIA_FUNC(Technosqueek_State_MoveHorizontal); \
  GET_MANIA_FUNC(Technosqueek_State_TurnHorizontal); \
  GET_MANIA_FUNC(Technosqueek_State_MoveVertical); \
  GET_MANIA_FUNC(Technosqueek_State_TurnVertical); \
  GET_MANIA_FUNC(Technosqueek_State_Fall); \
  GET_MANIA_FUNC(Clucker_State_Destroyed); \
  GET_MANIA_FUNC(Clucker_State_Appear); \
  GET_MANIA_FUNC(Clucker_State_ShootDelay); \
  GET_MANIA_FUNC(Clucker_State_Shoot); \
  GET_MANIA_FUNC(Clucker_State_Turn); \
  GET_MANIA_FUNC(Blaster_State_Move); \
  GET_MANIA_FUNC(Blaster_State_HandleTurn); \
  GET_MANIA_FUNC(Blaster_State_AttackPlayer); \
  GET_MANIA_FUNC(Blaster_State_MagnetAttract); \
  GET_MANIA_FUNC(Blaster_State_MagnetReleased); \
  GET_MANIA_FUNC(Blaster_State_Fall); \
  GET_MANIA_FUNC(Canista_State_Moving); \
  GET_MANIA_FUNC(Canista_State_Idle); \
  GET_MANIA_FUNC(Tubinaut_State_Move); \
  GET_MANIA_FUNC(Shutterbug_State_FlyAround); \
  GET_MANIA_FUNC(Shutterbug_State_ShakeFly); \
  GET_MANIA_FUNC(Shutterbug_State_FlyAway); \
  GET_MANIA_FUNC(MicDrop_State_CheckForPlayer); \
  GET_MANIA_FUNC(MicDrop_State_DropDown); \
  GET_MANIA_FUNC(MicDrop_State_DropRecoil); \
  GET_MANIA_FUNC(MicDrop_State_Idle); \
  GET_MANIA_FUNC(MicDrop_State_Swinging); \
  GET_MANIA_FUNC(MicDrop_State_Electrify); \
  GET_MANIA_FUNC(Spiny_State_Floor); \
  GET_MANIA_FUNC(Spiny_State_Shoot_Floor); \
  GET_MANIA_FUNC(Spiny_State_Wall); \
  GET_MANIA_FUNC(Spiny_State_Shoot_Wall); \
  GET_MANIA_FUNC(Grabber_State_CheckForGrab); \
  GET_MANIA_FUNC(Grabber_State_GrabDelay); \
  GET_MANIA_FUNC(Grabber_State_HandleTurn); \
  GET_MANIA_FUNC(Grabber_State_TryToGrab); \
  GET_MANIA_FUNC(Grabber_State_RiseUp); \
  GET_MANIA_FUNC(Grabber_State_GrabbedPlayer); \
  GET_MANIA_FUNC(Grabber_State_Struggle); \
  GET_MANIA_FUNC(Grabber_State_PlayerEscaped); \
  GET_MANIA_FUNC(Bubbler_State_MotherPatrol); \
  GET_MANIA_FUNC(Bubbler_State_FoundPlayer); \
  GET_MANIA_FUNC(Bubbler_State_AttackPlayer); \
  GET_MANIA_FUNC(Bubbler_StateProjectile_Seed); \
  GET_MANIA_FUNC(Bubbler_StateProjectile_Bubbler); \
  GET_MANIA_FUNC(Splats_State_BounceAround); \
  GET_MANIA_FUNC(Splats_State_JumpOutOfJar); \
  GET_MANIA_FUNC(Splats_State_HandleBouncing); \
  GET_MANIA_FUNC(Splats_State_HandleLanding); \
  GET_MANIA_FUNC(Splats_State_NoMoreJumps); \
  GET_MANIA_FUNC(Newtron_State_StartFly); \
  GET_MANIA_FUNC(Newtron_State_Fly); \
  GET_MANIA_FUNC(Newtron_State_Shoot); \
  GET_MANIA_FUNC(Chopper_State_Jump); \
  GET_MANIA_FUNC(Crabmeat_State_Projectile); \
  GET_MANIA_FUNC(Batbrain_State_CheckPlayerInRange); \
  GET_MANIA_FUNC(Batbrain_State_DropToPlayer); \
  GET_MANIA_FUNC(Batbrain_State_Fly); \
  GET_MANIA_FUNC(Batbrain_State_FlyToCeiling); \
  GET_MANIA_FUNC(Motobug_State_Smoke)
