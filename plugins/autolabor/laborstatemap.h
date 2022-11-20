#pragma once

#include <Core.h>

#include "df/job.h"
#include "df/job_type.h"
#include "df/unit_labor.h"

using namespace DFHack;
using namespace df::enums;

    enum dwarf_state : int {
    // Ready for a new task
    IDLE=0,

    // Busy with a useful task
    BUSY,

    // Busy with a useful task that requires a tool
    EXCLUSIVE,

    // In the military, can't work
    MILITARY,

    // Child or noble, can't work
    CHILD,

    // Doing something that precludes working, may be busy for a while
    OTHER
};

const int NUM_STATE = 6;

char const* state_names[] {
    "IDLE",
    "BUSY",
    "EXCLUSIVE",
    "MILITARY",
    "CHILD",
    "OTHER",
};

const dwarf_state dwarf_states[] = {
    dwarf_state::BUSY /* CarveFortification */,
    dwarf_state::BUSY /* DetailWall */,
    dwarf_state::BUSY /* DetailFloor */,
    dwarf_state::EXCLUSIVE /* Dig */,
    dwarf_state::EXCLUSIVE /* CarveUpwardStaircase */,
    dwarf_state::EXCLUSIVE /* CarveDownwardStaircase */,
    dwarf_state::EXCLUSIVE /* CarveUpDownStaircase */,
    dwarf_state::EXCLUSIVE /* CarveRamp */,
    dwarf_state::EXCLUSIVE /* DigChannel */,
    dwarf_state::EXCLUSIVE /* FellTree */,
    dwarf_state::BUSY /* GatherPlants */,
    dwarf_state::BUSY /* RemoveConstruction */,
    dwarf_state::BUSY /* CollectWebs */,
    dwarf_state::BUSY /* BringItemToDepot */,
    dwarf_state::BUSY /* BringItemToShop */,
    dwarf_state::OTHER /* Eat */,
    dwarf_state::OTHER /* GetProvisions */,
    dwarf_state::OTHER /* Drink */,
    dwarf_state::OTHER /* Drink2 */,
    dwarf_state::OTHER /* FillWaterskin */,
    dwarf_state::OTHER /* FillWaterskin2 */,
    dwarf_state::OTHER /* Sleep */,
    dwarf_state::BUSY /* CollectSand */,
    dwarf_state::BUSY /* Fish */,
    dwarf_state::EXCLUSIVE /* Hunt */,
    dwarf_state::OTHER /* HuntVermin */,
    dwarf_state::BUSY /* Kidnap */,
    dwarf_state::BUSY /* BeatCriminal */,
    dwarf_state::BUSY /* StartingFistFight */,
    dwarf_state::BUSY /* CollectTaxes */,
    dwarf_state::BUSY /* GuardTaxCollector */,
    dwarf_state::BUSY /* CatchLiveLandAnimal */,
    dwarf_state::BUSY /* CatchLiveFish */,
    dwarf_state::BUSY /* ReturnKill */,
    dwarf_state::BUSY /* CheckChest */,
    dwarf_state::BUSY /* StoreOwnedItem */,
    dwarf_state::BUSY /* PlaceItemInTomb */,
    dwarf_state::BUSY /* StoreItemInStockpile */,
    dwarf_state::BUSY /* StoreItemInBag */,
    dwarf_state::BUSY /* StoreItemInHospital */,
    dwarf_state::BUSY /* StoreItemInChest */,
    dwarf_state::BUSY /* StoreItemInCabinet */,
    dwarf_state::BUSY /* StoreWeapon */,
    dwarf_state::BUSY /* StoreArmor */,
    dwarf_state::BUSY /* StoreItemInBarrel */,
    dwarf_state::BUSY /* StoreItemInBin */,
    dwarf_state::BUSY /* SeekArtifact */,
    dwarf_state::BUSY /* SeekInfant */,
    dwarf_state::OTHER /* AttendParty */,
    dwarf_state::OTHER /* GoShopping */,
    dwarf_state::OTHER /* GoShopping2 */,
    dwarf_state::BUSY /* Clean */,
    dwarf_state::OTHER /* Rest */,
    dwarf_state::EXCLUSIVE /* PickupEquipment */,
    dwarf_state::BUSY /* DumpItem */,
    dwarf_state::OTHER /* StrangeMoodCrafter */,
    dwarf_state::OTHER /* StrangeMoodJeweller */,
    dwarf_state::OTHER /* StrangeMoodForge */,
    dwarf_state::OTHER /* StrangeMoodMagmaForge */,
    dwarf_state::OTHER /* StrangeMoodBrooding */,
    dwarf_state::OTHER /* StrangeMoodFell */,
    dwarf_state::OTHER /* StrangeMoodCarpenter */,
    dwarf_state::OTHER /* StrangeMoodMason */,
    dwarf_state::OTHER /* StrangeMoodBowyer */,
    dwarf_state::OTHER /* StrangeMoodTanner */,
    dwarf_state::OTHER /* StrangeMoodWeaver */,
    dwarf_state::OTHER /* StrangeMoodGlassmaker */,
    dwarf_state::OTHER /* StrangeMoodMechanics */,
    dwarf_state::BUSY /* ConstructBuilding */,
    dwarf_state::BUSY /* ConstructDoor */,
    dwarf_state::BUSY /* ConstructFloodgate */,
    dwarf_state::BUSY /* ConstructBed */,
    dwarf_state::BUSY /* ConstructThrone */,
    dwarf_state::BUSY /* ConstructCoffin */,
    dwarf_state::BUSY /* ConstructTable */,
    dwarf_state::BUSY /* ConstructChest */,
    dwarf_state::BUSY /* ConstructBin */,
    dwarf_state::BUSY /* ConstructArmorStand */,
    dwarf_state::BUSY /* ConstructWeaponRack */,
    dwarf_state::BUSY /* ConstructCabinet */,
    dwarf_state::BUSY /* ConstructStatue */,
    dwarf_state::BUSY /* ConstructBlocks */,
    dwarf_state::BUSY /* MakeRawGlass */,
    dwarf_state::BUSY /* MakeCrafts */,
    dwarf_state::BUSY /* MintCoins */,
    dwarf_state::BUSY /* CutGems */,
    dwarf_state::BUSY /* CutGlass */,
    dwarf_state::BUSY /* EncrustWithGems */,
    dwarf_state::BUSY /* EncrustWithGlass */,
    dwarf_state::BUSY /* DestroyBuilding */,
    dwarf_state::BUSY /* SmeltOre */,
    dwarf_state::BUSY /* MeltMetalObject */,
    dwarf_state::BUSY /* ExtractMetalStrands */,
    dwarf_state::BUSY /* PlantSeeds */,
    dwarf_state::BUSY /* HarvestPlants */,
    dwarf_state::BUSY /* TrainHuntingAnimal */,
    dwarf_state::BUSY /* TrainWarAnimal */,
    dwarf_state::BUSY /* MakeWeapon */,
    dwarf_state::BUSY /* ForgeAnvil */,
    dwarf_state::BUSY /* ConstructCatapultParts */,
    dwarf_state::BUSY /* ConstructBallistaParts */,
    dwarf_state::BUSY /* MakeArmor */,
    dwarf_state::BUSY /* MakeHelm */,
    dwarf_state::BUSY /* MakePants */,
    dwarf_state::BUSY /* StudWith */,
    dwarf_state::BUSY /* ButcherAnimal */,
    dwarf_state::BUSY /* PrepareRawFish */,
    dwarf_state::BUSY /* MillPlants */,
    dwarf_state::BUSY /* BaitTrap */,
    dwarf_state::BUSY /* MilkCreature */,
    dwarf_state::BUSY /* MakeCheese */,
    dwarf_state::BUSY /* ProcessPlants */,
    dwarf_state::BUSY /* ProcessPlantsBag */,
    dwarf_state::BUSY /* ProcessPlantsVial */,
    dwarf_state::BUSY /* ProcessPlantsBarrel */,
    dwarf_state::BUSY /* PrepareMeal */,
    dwarf_state::BUSY /* WeaveCloth */,
    dwarf_state::BUSY /* MakeGloves */,
    dwarf_state::BUSY /* MakeShoes */,
    dwarf_state::BUSY /* MakeShield */,
    dwarf_state::BUSY /* MakeCage */,
    dwarf_state::BUSY /* MakeChain */,
    dwarf_state::BUSY /* MakeFlask */,
    dwarf_state::BUSY /* MakeGoblet */,
    dwarf_state::BUSY /* MakeInstrument */,
    dwarf_state::BUSY /* MakeToy */,
    dwarf_state::BUSY /* MakeAnimalTrap */,
    dwarf_state::BUSY /* MakeBarrel */,
    dwarf_state::BUSY /* MakeBucket */,
    dwarf_state::BUSY /* MakeWindow */,
    dwarf_state::BUSY /* MakeTotem */,
    dwarf_state::BUSY /* MakeAmmo */,
    dwarf_state::BUSY /* DecorateWith */,
    dwarf_state::BUSY /* MakeBackpack */,
    dwarf_state::BUSY /* MakeQuiver */,
    dwarf_state::BUSY /* MakeBallistaArrowHead */,
    dwarf_state::BUSY /* AssembleSiegeAmmo */,
    dwarf_state::BUSY /* LoadCatapult */,
    dwarf_state::BUSY /* LoadBallista */,
    dwarf_state::BUSY /* FireCatapult */,
    dwarf_state::BUSY /* FireBallista */,
    dwarf_state::BUSY /* ConstructMechanisms */,
    dwarf_state::BUSY /* MakeTrapComponent */,
    dwarf_state::BUSY /* LoadCageTrap */,
    dwarf_state::BUSY /* LoadStoneTrap */,
    dwarf_state::BUSY /* LoadWeaponTrap */,
    dwarf_state::BUSY /* CleanTrap */,
    dwarf_state::BUSY /* CastSpell */,
    dwarf_state::BUSY /* LinkBuildingToTrigger */,
    dwarf_state::BUSY /* PullLever */,
    dwarf_state::BUSY /* BrewDrink */,
    dwarf_state::BUSY /* ExtractFromPlants */,
    dwarf_state::BUSY /* ExtractFromRawFish */,
    dwarf_state::BUSY /* ExtractFromLandAnimal */,
    dwarf_state::BUSY /* TameVermin */,
    dwarf_state::BUSY /* TameAnimal */,
    dwarf_state::BUSY /* ChainAnimal */,
    dwarf_state::BUSY /* UnchainAnimal */,
    dwarf_state::BUSY /* UnchainPet */,
    dwarf_state::BUSY /* ReleaseLargeCreature */,
    dwarf_state::BUSY /* ReleasePet */,
    dwarf_state::BUSY /* ReleaseSmallCreature */,
    dwarf_state::BUSY /* HandleSmallCreature */,
    dwarf_state::BUSY /* HandleLargeCreature */,
    dwarf_state::BUSY /* CageLargeCreature */,
    dwarf_state::BUSY /* CageSmallCreature */,
    dwarf_state::BUSY /* RecoverWounded */,
    dwarf_state::BUSY /* DiagnosePatient */,
    dwarf_state::BUSY /* ImmobilizeBreak */,
    dwarf_state::BUSY /* DressWound */,
    dwarf_state::BUSY /* CleanPatient */,
    dwarf_state::BUSY /* Surgery */,
    dwarf_state::BUSY /* Suture */,
    dwarf_state::BUSY /* SetBone */,
    dwarf_state::BUSY /* PlaceInTraction */,
    dwarf_state::BUSY /* DrainAquarium */,
    dwarf_state::BUSY /* FillAquarium */,
    dwarf_state::BUSY /* FillPond */,
    dwarf_state::BUSY /* GiveWater */,
    dwarf_state::BUSY /* GiveFood */,
    dwarf_state::BUSY /* GiveWater2 */,
    dwarf_state::BUSY /* GiveFood2 */,
    dwarf_state::BUSY /* RecoverPet */,
    dwarf_state::BUSY /* PitLargeAnimal */,
    dwarf_state::BUSY /* PitSmallAnimal */,
    dwarf_state::BUSY /* SlaughterAnimal */,
    dwarf_state::BUSY /* MakeCharcoal */,
    dwarf_state::BUSY /* MakeAsh */,
    dwarf_state::BUSY /* MakeLye */,
    dwarf_state::BUSY /* MakePotashFromLye */,
    dwarf_state::BUSY /* FertilizeField */,
    dwarf_state::BUSY /* MakePotashFromAsh */,
    dwarf_state::BUSY /* DyeThread */,
    dwarf_state::BUSY /* DyeCloth */,
    dwarf_state::BUSY /* SewImage */,
    dwarf_state::BUSY /* MakePipeSection */,
    dwarf_state::BUSY /* OperatePump */,
    dwarf_state::OTHER /* ManageWorkOrders */,
    dwarf_state::OTHER /* UpdateStockpileRecords */,
    dwarf_state::OTHER /* TradeAtDepot */,
    dwarf_state::BUSY /* ConstructHatchCover */,
    dwarf_state::BUSY /* ConstructGrate */,
    dwarf_state::BUSY /* RemoveStairs */,
    dwarf_state::BUSY /* ConstructQuern */,
    dwarf_state::BUSY /* ConstructMillstone */,
    dwarf_state::BUSY /* ConstructSplint */,
    dwarf_state::BUSY /* ConstructCrutch */,
    dwarf_state::BUSY /* ConstructTractionBench */,
    dwarf_state::BUSY /* CleanSelf */,
    dwarf_state::BUSY /* BringCrutch */,
    dwarf_state::BUSY /* ApplyCast */,
    dwarf_state::BUSY /* CustomReaction */,
    dwarf_state::BUSY /* ConstructSlab */,
    dwarf_state::BUSY /* EngraveSlab */,
    dwarf_state::BUSY /* ShearCreature */,
    dwarf_state::BUSY /* SpinThread */,
    dwarf_state::BUSY /* PenLargeAnimal */,
    dwarf_state::BUSY /* PenSmallAnimal */,
    dwarf_state::BUSY /* MakeTool */,
    dwarf_state::BUSY /* CollectClay */,
    dwarf_state::BUSY /* InstallColonyInHive */,
    dwarf_state::BUSY /* CollectHiveProducts */,
    dwarf_state::OTHER /* CauseTrouble */,
    dwarf_state::OTHER /* DrinkBlood */,
    dwarf_state::OTHER /* ReportCrime */,
    dwarf_state::OTHER /* ExecuteCriminal */,
    dwarf_state::BUSY /* TrainAnimal */,
    dwarf_state::BUSY /* CarveTrack */,
    dwarf_state::BUSY /* PushTrackVehicle */,
    dwarf_state::BUSY /* PlaceTrackVehicle */,
    dwarf_state::BUSY /* StoreItemInVehicle */,
    dwarf_state::BUSY /* GeldAnimal */,
    dwarf_state::BUSY /* MakeFigurine */,
    dwarf_state::BUSY /* MakeAmulet */,
    dwarf_state::BUSY /* MakeScepter */,
    dwarf_state::BUSY /* MakeCrown */,
    dwarf_state::BUSY /* MakeRing */,
    dwarf_state::BUSY /* MakeEarring */,
    dwarf_state::BUSY /* MakeBracelet */,
    dwarf_state::BUSY /* MakeGem */,
    dwarf_state::BUSY /* PutItemOnDisplay */,
    dwarf_state::OTHER /* unk_fake_no_job */,
    dwarf_state::OTHER /* InterrogateSubject */,
    dwarf_state::OTHER /* unk_fake_no_activity */,
};

#define ARRAY_COUNT(array) (sizeof(array)/sizeof((array)[0]))

const int dwarf_state_count = ARRAY_COUNT(dwarf_states);

#undef ARRAY_COUNT
