#ifndef _ATOMIC_2012_01_09_H_
  #define _ATOMIC_2012_01_09_H_

  namespace std
  {
    template<typename atomic_integral_type>
    atomic_integral_type atomic_load(const atomic_integral_type*);

    template<typename atomic_integral_type>
    atomic_integral_type atomic_load(const volatile atomic_integral_type*);

    template<typename atomic_integral_type>
    void atomic_store(atomic_integral_type*, atomic_integral_type);

    template<typename atomic_integral_type>
    void atomic_store(volatile atomic_integral_type*, atomic_integral_type);
  }

  class atomic_helper
  {
  private:
    template<typename atomic_integral_type>
    friend atomic_integral_type std::atomic_load(const atomic_integral_type*);

    template<typename atomic_integral_type>
    friend atomic_integral_type std::atomic_load(const volatile atomic_integral_type*);

    template<typename atomic_integral_type>
    friend void std::atomic_store(atomic_integral_type*, atomic_integral_type);

    template<typename atomic_integral_type>
    friend void std::atomic_store(volatile atomic_integral_type*, atomic_integral_type);

    static void enable_all_interrupts () { asm volatile ("sei"); }
    static void disable_all_interrupts() { asm volatile ("cli"); }
  };

#endif // _ATOMIC_2012_01_09_H_
