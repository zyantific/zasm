  #pragma once
  
  #include <cstdint>
  #include <zasm/base/mode.hpp>
  #include <zasm/core/bitsize.hpp>
  
  namespace zasm
  {
  
      class Label
      {
      public:
          enum class Id : int32_t
          {
              Invalid = -1,
          };
  
      private:
          Id _id{ Id::Invalid };
  
      public:
          constexpr Label() noexcept = default;
          constexpr explicit Label(const Id id) noexcept
              : _id{ id }
          {
          }
  
          constexpr Id getId() const noexcept
          {
              return _id;
          }
  
          constexpr bool isValid() const noexcept
          {
              return _id != Id::Invalid;
          }
  
          BitSize getBitSize() const noexcept
          {
              return BitSize::_0;
          }
  
          BitSize getBitSize(MachineMode) const noexcept
          {
              return getBitSize();
          }
      };
  
      /// <summary>
      /// Constant for an empty/invalid label.
      /// </summary>
      constexpr Label kInvalidLabel{};
  
  } // namespace zasm
