readonly DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

cd "$DIR/src" && astyle  "*.cpp" -r --options=../astylerc
cd "$DIR/include" && astyle "*.h" -r --options=../astylerc
find "$DIR" -name "*.orig" -delete
