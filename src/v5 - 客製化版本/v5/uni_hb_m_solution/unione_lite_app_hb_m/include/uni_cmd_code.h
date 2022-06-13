#ifndef INC_UNI_CMD_CODE_H_
#define INC_UNI_CMD_CODE_H_

typedef struct {
  uni_u8      cmd_code; /* cmd code fro send base on SUCP */
  const char  *cmd_str; /* action string on UDP */;
} cmd_code_map_t;

const cmd_code_map_t g_cmd_code_arry[] = {
  {0x0, "wakeup_uni"},
  {0x1, "Pwr_Fun"},
  {0x2, "Attack"},
  {0x3, "HP"},
  {0x4, "Potion"},
  {0x5, "enAttack"},
  {0x6, "enPotion"},
  {0x7, "enHP"},
  {0x8, "startStudy"},
  {0x9, "clearStudy"},
  {0xa, "clearStuCmd"},
  {0xb, "clearStuWakeup"},
  {0xc, "startStuWakeup"},
  {0xd, "stuCmd_jx_0"},
  {0xe, "stuCmd_jx_1"},
  {0xf, "stuCmd_jx_2"},
  {0x10, "startStuCmd"},
};

#endif
