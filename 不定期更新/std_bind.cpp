// std::bind関数について書く
// 構造ーーーーー
// namespace std {
//   template <class F, class... BoundArgs>
//   unspecified bind(F&& f, BoundArgs&&... bound_args);           // (1) C++11

//   template <class F, class... BoundArgs>
//   constexpr unspecified bind(F&& f, BoundArgs&&... bound_args); // (1) C++20

//   template <class R, class F, class... BoundArgs>
//   unspecified bind(F&& f, BoundArgs&&... bound_args);           // (2) C++11

//   template <class R, class F, class... BoundArgs>
//   constexpr unspecified bind(F&& f, BoundArgs&&... bound_args); // (2) C++20
// }
// ーーーーーー
