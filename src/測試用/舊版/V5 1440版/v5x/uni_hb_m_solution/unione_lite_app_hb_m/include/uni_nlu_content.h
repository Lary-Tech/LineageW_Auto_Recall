#ifndef INC_UNI_NLU_CONTENT_H_
#define INC_UNI_NLU_CONTENT_H_

#include "uni_nlu_content_type.h"
const char* const g_nlu_content_str[] = {
[eCMD_wakeup_uni] = "{\"asr\":\"早上好中國\",\"cmd\":\"wakeup_uni\",\"pcm\":\"[103]\"}",
[eCMD_Pwr_Fun] = "{\"asr\":\"一令命藏隐\",\"cmd\":\"Pwr_Fun\",\"pcm\":\"[]\"}",
[eCMD_Attack] = "{\"asr\":\"遭受敌人攻击了\",\"cmd\":\"Attack\",\"pcm\":\"[104]\"}",
[eCMD_HP] = "{\"asr\":\"体力不足了\",\"cmd\":\"HP\",\"pcm\":\"[105]\"}",
[eCMD_Potion] = "{\"asr\":\"需要補充一下藥水\",\"cmd\":\"Potion\",\"pcm\":\"[106]\"}",
[eCMD_enAttack] = "{\"asr\":\"英文攻擊\",\"cmd\":\"enAttack\",\"pcm\":\"[107]\"}",
[eCMD_enPotion] = "{\"asr\":\"英文藥水\",\"cmd\":\"enPotion\",\"pcm\":\"[108]\"}",
[eCMD_enHP] = "{\"asr\":\"英文體力\",\"cmd\":\"enHP\",\"pcm\":\"[109]\"}",
[eCMD_startStudy] = "{\"asr\":\"开始学习\",\"cmd\":\"startStudy\",\"pcm\":\"[110, 111, 112, 113, 114, 115]\"}",
[eCMD_clearStudy] = "{\"asr\":\"重置学习\",\"cmd\":\"clearStudy\",\"pcm\":\"[116]\"}",
[eCMD_clearStuCmd] = "{\"asr\":\"清除学习命令词\",\"cmd\":\"clearStuCmd\",\"pcm\":\"[117]\"}",
[eCMD_clearStuWakeup] = "{\"asr\":\"清除学习唤醒词\",\"cmd\":\"clearStuWakeup\",\"pcm\":\"[118]\"}",
[eCMD_startStuWakeup] = "{\"asr\":\"开始学习唤醒词\",\"cmd\":\"startStuWakeup\",\"pcm\":\"[]\"}",
[eCMD_stuCmd_jx_0] = "{\"asr\":\"一二令命藏隐\",\"cmd\":\"stuCmd_jx_0\",\"pcm\":\"[119]\"}",
[eCMD_stuCmd_jx_1] = "{\"asr\":\"一三令命藏隐\",\"cmd\":\"stuCmd_jx_1\",\"pcm\":\"[120]\"}",
[eCMD_stuCmd_jx_2] = "{\"asr\":\"一四令命藏隐\",\"cmd\":\"stuCmd_jx_2\",\"pcm\":\"[121]\"}",
[eCMD_startStuCmd] = "{\"asr\":\"开始学习命令词\",\"cmd\":\"startStuCmd\",\"pcm\":\"[]\"}",
};

/*TODO perf sort by hashcode O(logN), now version O(N)*/
const uni_nlu_content_mapping_t g_nlu_content_mapping[] = {
  {712525978U/*早上好中國*/, eCMD_wakeup_uni, NULL},
  {3604824431U/*一令命藏隐*/, eCMD_Pwr_Fun, NULL},
  {3142907461U/*遭受敌人攻击了*/, eCMD_Attack, NULL},
  {2320283775U/*遭受敌人*/, eCMD_Attack, NULL},
  {2500137592U/*遭受*/, eCMD_Attack, NULL},
  {988123976U/*体力不足了*/, eCMD_HP, NULL},
  {1802617339U/*体力已经见底了*/, eCMD_HP, NULL},
  {2411628380U/*体力*/, eCMD_HP, NULL},
  {3076482137U/*需要補充一下藥水*/, eCMD_Potion, NULL},
  {451753887U/*需要更多的药水*/, eCMD_Potion, NULL},
  {2523735638U/*需要*/, eCMD_Potion, NULL},
  {1103106233U/*英文攻擊*/, eCMD_enAttack, NULL},
  {1162480637U/*英文藥水*/, eCMD_enPotion, NULL},
  {1209071597U/*英文體力*/, eCMD_enHP, NULL},
  {223153613U/*开始学习*/, eCMD_startStudy, NULL},
  {298988278U/*重置学习*/, eCMD_clearStudy, NULL},
  {719869020U/*清除学习命令词*/, eCMD_clearStuCmd, NULL},
  {1034240088U/*清除学习唤醒词*/, eCMD_clearStuWakeup, NULL},
  {453225561U/*开始学习唤醒词*/, eCMD_startStuWakeup, NULL},
  {2645624461U/*一二令命藏隐*/, eCMD_stuCmd_jx_0, NULL},
  {241983436U/*一三令命藏隐*/, eCMD_stuCmd_jx_1, NULL},
  {2539546652U/*一四令命藏隐*/, eCMD_stuCmd_jx_2, NULL},
  {138854493U/*开始学习命令词*/, eCMD_startStuCmd, NULL},
};

#endif
