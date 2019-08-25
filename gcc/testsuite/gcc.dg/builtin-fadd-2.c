/* { dg-do link } */
/* { dg-options "-O2 -frounding-math" } */

extern int link_error (int);

#define TEST(FN, VAL1, VAL2, RESULT) \
  if (__builtin_##FN (VAL1, VAL2) != RESULT) link_error (__LINE__);

int
main (void)
{
  TEST(fadd, 1, 1.1, 2.1F);
  TEST(fadd, 3, 4.2, 7.2F);
  TEST(fadd, 2, 4.3, 6.3F);
  TEST(fadd, -2, -2.4, -4.4F);
  TEST(fadd, -3, -3.6, -6.6F); 
  TEST(fadd, -5.3, -5.4, -10.7F);
  TEST(fadd, 8, 0.8, 8.8F);
  TEST(fadd, 0.5, 0.4, 0.9F);

  TEST(faddl, 1.0L, 1.1L, 2.1F);
  TEST(faddl, 3.0L, 4.2L, 7.2F);
  TEST(faddl, 2.0L, 4.3L, 6.3F);
  TEST(faddl, -2.0L, -2.4L, -4.4F);
  TEST(faddl, -3.0L, -3.6L, -6.6F); 
  TEST(faddl, -5.3L, -5.4L, -10.7F);
  TEST(faddl, 8.0L, 0.8L, 8.8F);
  TEST(faddl, 0.5L, 0.4L, 0.9F);

  TEST(daddl, 1.0L, 1.1L, 2.1);
  TEST(daddl, 3.0L, 4.2L, 7.2);
  TEST(daddl, 2.0L, 4.3L, 6.3);
  TEST(daddl, -2.0L, -2.4L, -4.4);
  TEST(daddl, -3.0L, -3.6L, -6.6); 
  TEST(daddl, -5.3L, -5.4L, -10.7);
  TEST(daddl, 8.0L, 0.8L, 8.8);
  TEST(daddl, 0.5L, 0.4L, 0.9);

  return 0;
} 
