#include "GameAPI/Game.h"

#include "Boilerplate/ERZ/PhantomMystic.h"
#include "Boilerplate/ERZ/PhantomShinobi.h"
#include "Boilerplate/ERZ/PhantomEgg.h"
#include "Boilerplate/TMZ/CrimsonEye.h"
#include "Boilerplate/MMZ/Gachapandora.h"
#include "Boilerplate/MMZ/EggPistonsMKII.h"
#include "Boilerplate/LRZ/RockDrill.h"
#include "Boilerplate/LRZ/HeavyKing.h"
#include "Boilerplate/LRZ/HeavyRider.h"
#include "Boilerplate/LRZ/DrillerdroidO.h"
#include "Boilerplate/LRZ/Drillerdroid.h"
#include "Boilerplate/OOZ/MegaOctus.h"
#include "Boilerplate/OOZ/MeterDroid.h"
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

extern int32 AttackableClasses_startidx;
bool32 Generic_CheckVulnerable(Entity* self);
Hitbox* Generic_GetHitbox(Entity* self);
void Generic_OnHit(EntityPlayer* player, Entity* self);
void Generic_BadnikBreak_NoEntity(EntityPlayer* player, Vector2 position, bool32 spawnAnimals);

void Generic_BadnikBreak(EntityPlayer* player, Entity* entity, bool32 spawnAnimals);

// =============================================================================

// -----------------------------------------------------------------------------

// =============================================================================
#define REGISTER_ENEMY(name) MOD_REGISTER_OBJ_OVERLOAD(name, NULL, NULL, NULL, NULL, NULL, name##_EnemyInfoHook, NULL, NULL, NULL)

#define HOOK_ENEMY_OBJECTS \
  OBJ_PHANTOMMYSTIC_SETUP; \
  OBJ_PHANTOMSHINOBI_SETUP; \
  OBJ_PHANTOMEGG_SETUP; \
  OBJ_CRIMSONEYE_SETUP; \
  OBJ_GACHAPANDORA_SETUP; \
  OBJ_EGGPISTONSMKII_SETUP; \
  OBJ_ROCKDRILL_SETUP; \
  OBJ_HEAVYKING_SETUP; \
  OBJ_HEAVYRIDER_SETUP; \
  OBJ_DRILLERDROIDO_SETUP; \
  OBJ_DRILLERDROID_SETUP; \
  OBJ_MEGAOCTUS_SETUP; \
  OBJ_METERDROID_SETUP; \
  OBJ_HEAVYMYSTIC_SETUP; \
  OBJ_DBTOWER_SETUP; \
  OBJ_UBERCATERKILLER_SETUP; \
  OBJ_LAUNDROMOBILE_SETUP; \
  OBJ_METALSONIC_SETUP; \
  OBJ_GIGAMETAL_SETUP; \
  OBJ_HOTARUHIWATT_SETUP; \
  OBJ_HEAVYSHINOBI_SETUP; \
  OBJ_SHIVERSAW_SETUP; \
  OBJ_BIGSQUEEZE_SETUP; \
  OBJ_WEATHERMOBILE_SETUP; \
  OBJ_AMOEBADROID_SETUP; \
  OBJ_DEROBOT_SETUP; \
  OBJ_DDWRECKER_SETUP; \
  \
  OBJ_FLASHERMKII_SETUP; \
  OBJ_TURBOTURTLE_SETUP; \
  OBJ_SENTRYBUG_SETUP; \
  OBJ_BALLHOG_SETUP; \
  OBJ_POHBEE_SETUP; \
  OBJ_SCARAB_SETUP; \
  OBJ_MECHABU_SETUP; \
  OBJ_FIREWORM_SETUP; \
  OBJ_REXON_SETUP; \
  OBJ_TOXOMISTER_SETUP; \
  OBJ_OCTUS_SETUP; \
  OBJ_SOL_SETUP; \
  OBJ_AQUIS_SETUP; \
  OBJ_RATTLEKILLER_SETUP; \
  OBJ_ROLLERMKII_SETUP; \
  OBJ_VULTRON_SETUP; \
  OBJ_BUMPALO_SETUP; \
  OBJ_ARMADILOID_SETUP; \
  OBJ_CACTULA_SETUP; \
  OBJ_HATTERKILLER_SETUP; \
  OBJ_TURBOSPIKER_SETUP; \
  OBJ_BUGGERNAUT_SETUP; \
  OBJ_MEGACHOPPER_SETUP; \
  OBJ_JAWZ_SETUP; \
  OBJ_JELLYGNITE_SETUP; \
  OBJ_BLASTOID_SETUP; \
  OBJ_POINTDEXTER_SETUP; \
  OBJ_KABASIRA_SETUP; \
  OBJ_DANGO_SETUP; \
  OBJ_KANABUN_SETUP; \
  OBJ_HOTARUMKII_SETUP; \
  OBJ_HOTARU_SETUP; \
  OBJ_WOODROW_SETUP; \
  OBJ_DRAGONFLY_SETUP; \
  OBJ_ICEBOMBA_SETUP; \
  OBJ_JUGGLESAW_SETUP; \
  OBJ_FBZTRASH_SETUP; \
  OBJ_TECHNOSQUEEK_SETUP; \
  OBJ_CLUCKER_SETUP; \
  OBJ_BLASTER_SETUP; \
  OBJ_CANISTA_SETUP; \
  OBJ_TUBINAUT_SETUP; \
  OBJ_SHUTTERBUG_SETUP; \
  OBJ_MICDROP_SETUP; \
  OBJ_SPINY_SETUP; \
  OBJ_GRABBER_SETUP; \
  OBJ_CATERKILLERJR_SETUP; \
  OBJ_BUBBLER_SETUP; \
  OBJ_SPLATS_SETUP; \
  OBJ_NEWTRON_SETUP; \
  OBJ_CHOPPER_SETUP; \
  OBJ_CRABMEAT_SETUP; \
  OBJ_BATBRAIN_SETUP; \
  OBJ_MOTOBUG_SETUP; \
  OBJ_BUZZBOMBER_SETUP