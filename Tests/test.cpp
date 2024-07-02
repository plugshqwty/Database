#include "pch.h"
#include "myvalidator.h"

TEST(MyValidator, Dlina) {
	MyValidator v;
  EXPECT_TRUE(v.validatePassword("Looong111"));
  EXPECT_FALSE(v.validatePassword("Short1"));
}
TEST(MyValidator, Zaglavnie) {
	MyValidator v;
	EXPECT_TRUE(v.validatePassword("EstZaglavnie1"));
	EXPECT_FALSE(v.validatePassword("netzaglavnih1"));
}
TEST(MyValidator, Strochnie) {
	MyValidator v;
	EXPECT_TRUE(v.validatePassword("EstStrochnie1"));
	EXPECT_FALSE(v.validatePassword("NETSTROCHNIH1"));
}
TEST(MyValidator, Cifri) {
	MyValidator v;
	EXPECT_TRUE(v.validatePassword("EeestCifri111"));
	EXPECT_FALSE(v.validatePassword("NeeetCifr"));
}
TEST(MyValidator, Password) {
	MyValidator v;
	EXPECT_TRUE(v.validatePassword("EeestCifri111"));
	EXPECT_FALSE(v.validatePassword("Se1"));
	EXPECT_FALSE(v.validatePassword("eeeeeeeeeee1"));
	EXPECT_FALSE(v.validatePassword("SSSSSSSSSSSSS1"));
	EXPECT_FALSE(v.validatePassword("SeSSSEeeee"));
}

TEST(MyValidator, ShortLogin) {
	MyValidator v;
	EXPECT_TRUE(v.validateLogin("fomina.m.i"));
	EXPECT_FALSE(v.validateLogin("we"));
}
TEST(MyValidator, LongLogin) {
	MyValidator v;
	EXPECT_TRUE(v.validateLogin("fomina.m.i"));
	EXPECT_FALSE(v.validateLogin("fomina.maria.igorevna.23052006mmmmmm"));
}
TEST(MyValidator, bukvaLogina) {
	MyValidator v;
	EXPECT_TRUE(v.validateLogin("f34123"));
	EXPECT_FALSE(v.validateLogin("12345674"));
}
TEST(MyValidator, Login) {
	MyValidator v;
	EXPECT_TRUE(v.validateLogin("Wewealka"));
	EXPECT_FALSE(v.validateLogin("Se1eeeeeeeeeee1234567890uuuuuuu"));
	EXPECT_FALSE(v.validateLogin("1111"));
	EXPECT_FALSE(v.validateLogin("Se3"));
	
}