/* { dg-do link } */
/* { dg-require-effective-target inf } */

extern int link_error (int);

#define TEST(FN, VAL1, VAL2, RESULT) \
  if (__builtin_##FN (VAL1, VAL2) != RESULT) link_error (__LINE__);

int
main (void)
{
  TEST(fadd, 0, 0, 0.0F);
  TEST(fadd, 1, -1, 0.0F);
  TEST(fadd, -1, -1.5, -2.5F);
  TEST(fadd, 1.4, 1.6, 3.0F);
  TEST(fadd, 2.5, 1.5, 4.0F);
  TEST(fadd, __FLT_MAX__, __FLT_MAX__/2, __builtin_inff ());
  
  TEST(faddl, 0.0L, 0.0L, 0.0F);
  TEST(faddl, 1.0L, -1.0L, 0.0F);
  TEST(faddl, -1.0L, -1.5L, -2.5F);
  TEST(faddl, 1.4L, 1.6L, 3.0F);
  TEST(faddl, 2.5L, 1.5L, 4.0F);
  TEST(faddl, __FLT_MAX__, __FLT_MAX__/2, __builtin_inff ());

  TEST(daddl, 0L, 0L, 0.0);
  TEST(daddl, 1L, -1L, 0.0);
  TEST(daddl, -1L, -1.5L, -2.5);
  TEST(daddl, 1.4L, 1.6L, 3.0);
  TEST(daddl, 2.5L, 1.5L, 4.0);
  TEST(daddl, __DBL_MAX__, __DBL_MAX__/2, __builtin_inf ());
  return 0;
}
