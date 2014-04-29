class Solution {
public:
/*
    struct split
    {
      enum empties_t { empties_ok, no_empties };
    };
    
    template <typename Container>
    Container& split(
      Container&                            result,
      const typename Container::value_type& s,
      const typename Container::value_type& delimiters,
      split::empties_t                      empties = split::empties_ok )
    {
      result.clear();
      size_t current;
      size_t next = -1;
      do
      {
        if (empties == split::no_empties)
        {
          next = s.find_first_not_of( delimiters, next + 1 );
          if (next == Container::value_type::npos) break;
          next -= 1;
        }
        current = next + 1;
        next = s.find_first_of( delimiters, current );
        result.push_back( s.substr( current, next - current ) );
      }
      while (next != Container::value_type::npos);
      return result;
    }
*/
    string simplifyPath(string path) {
        /*
        vector<string> simplPath;
        int start, end;
        start = end = 0;
        while (end < path.size()) {
            while (end < path.size() && path[end] == '/') {
                ++end;
            }
            start = end;
            while (end < path.size() && path[end] != '/') {
                ++end;
            }
            string each = path.substr(start, end - start);
            if (each == "..") {
                if (!simplPath.empty()) {
                    simplPath.pop_back();
                }
            } else if (each == ".") {
                continue;
            } else if (!each.empty()) {
                simplPath.push_back(each);
            }
        }
        string result;
        for (auto &each : simplPath) {
            result += "/" + each;
        }
        if (result.empty()) {
            result = "/";
        }
        return result;
        */
        stack<string> S;
        int start = -1;
        for (int end = 0; end <= path.size(); ++end) {
            if (start >= 0 && (end == path.size() || path[end] == '/')) {
                string entry = path.substr(start, end - start);
                start = -1;
                if (entry == "..") {
                    if (!S.empty()) {
                        S.pop();
                    }
                } else if (entry == ".") {
                    continue;
                } else if (!entry.empty()) {
                    S.push(entry);
                }
            } else if (start < 0 && end < path.size() && path[end] != '/') {
                start = end;
            }
        }
        if (S.empty()) {
            return "/";
        } else {
            string result;
            while (!S.empty()) {
                result = "/" + S.top() + result;
                S.pop();
            }
            return result;
        }
    }
};
