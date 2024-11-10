class Solution {
public:
    string simplifyPath(string path) {
        vector<string> part;
        string res;
        int i = 0, start = 0, end = 0;

        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()) i++;
            if (i == path.size()) break;
            start = i;
            // end = i; // EPoint
            while (path[i] != '/' && i < path.size()) { // EPoint
                i++;
            }
            end = i - 1;
            string t = path.substr(start, end - start + 1); // EPoint
            if (t == "..") {
                if (!part.empty()) part.pop_back();
            } else if (t != ".") {
                part.push_back(t);
            }
        }
        if (part.empty()) return "/";
        for (i = 0; i < part.size(); i++) {
            res += "/" + part[i];
        }

        return res;
    }

/** My Deprecated Solution:
        int n = path.size();
        if (n <= 1) return path;
        int cur = n - 1, pre = cur - 1, ndot = 0, nup = 0, nslash = 0;
        string res;

        while (pre >= 0) {
            ndot = 0; nslash = 0;
            while (path[pre] != '/') {
                if (path[pre] == '.') ndot++;
                pre--;
            }

            while (pre > 0 && path[pre] == '/') {
                pre--; nslash++;
            }

            if (ndot == 1) { // /.././
                cur = pre;
                --pre;
                continue;   
            }

            if (nup > 0) { // EPoint: must be here
                if (ndot == 2) {
                    ++nup;
                } else {
                    --nup; // EPoint: must be here --
                }
                cur = pre;
                --pre;
                continue;
            }

            if (path[cur] == '/') {
                if (cur - pre > 1) {
                    if (ndot == 0 || ndot >= 3) { // /home/foo/ | /home/.../
                        res = path.substr(pre + nslash, cur - pre) + res;
                    } else if (ndot == 2) { // /home/../
                        ++nup;
                    }
                }
            } else {
                if (cur - pre >= 1) {
                    if (ndot == 0 || ndot >= 3) { // /home/foo | /home/...
                        res = path.substr(pre + nslash, cur - pre) + res;
                    } else if (ndot == 2) { // /home/..
                        nup++;
                    }
                } else { // cur - pre must >= 1
                    return res;
                }
            }
            cur = pre;
            --pre;
            if ((nup > 0) && (cur <= 0)) return "/";
        }

        return res;
    }
*/
};