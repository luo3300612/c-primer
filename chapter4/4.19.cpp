//左边为真，右边，先自增返回之前的结果再解引用，指向非0时为真，但自增会导致后续的未定义行为
//先计算左边，自增返回自增之前，然后右边是自增之后的值
//未定义的行为