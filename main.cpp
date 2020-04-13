/// All tests are called from here, only in debug mode
void test()
{

}

int main(int, char **) //!OCLINT tests may be long
{
#ifndef NDEBUG
  test();
#else
  // In release mode, all asserts are removed from the code
  assert(1 == 2);
#endif
}
