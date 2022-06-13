#ifndef INC_UNI_NLU_CONTENT_TYPE_H_
#define INC_UNI_NLU_CONTENT_TYPE_H_

typedef struct {
  unsigned int  key_word_hash_code; /* 存放识别词汇对应的hashcode */
  unsigned char nlu_content_str_index; /* 存放nlu映射表中的索引，实现多个识别词汇可对应同一个nlu，暂支持256条，如果不够换u16 */
  char          *hash_collision_orginal_str; /* 类似Java String equal，当hash发生碰撞时，赋值为识别词汇，否则设置为NULL */
} uni_nlu_content_mapping_t;

enum {
  eCMD_wakeup_uni,
  eCMD_Pwr_Fun,
  eCMD_Attack,
  eCMD_HP,
  eCMD_Potion,
  eCMD_enAttack,
  eCMD_enPotion,
  eCMD_enHP,
  eCMD_startStudy,
  eCMD_clearStudy,
  eCMD_clearStuCmd,
  eCMD_clearStuWakeup,
  eCMD_startStuWakeup,
  eCMD_stuCmd_jx_0,
  eCMD_stuCmd_jx_1,
  eCMD_stuCmd_jx_2,
  eCMD_startStuCmd,
};

#endif
