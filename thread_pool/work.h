namespace Work {
  enum class Type {
    FINISH,
    CONTINUE
  };

  typedef std::function<Work::Type()> Callable;
}
