#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
  Segment(int s = 0, int e = 0) : start(s), end(e) {}
  bool operator<(const Segment &seg) const { return start < seg.start; }
};

int two_min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

int two_max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

void segment_intersect(Segment &seg1, Segment &seg2,
                       vector<Segment> &segStack) {
  if (seg1.end < seg2.start) {
    if (segStack.size() == 0) {
      segStack.emplace_back(seg1);
    }
    segStack.emplace_back(seg2);
  } else {
    Segment intersection(two_max(seg1.start, seg2.start),
                         two_min(seg1.end, seg2.end));
    if (segStack.size() > 0) {
      segStack.pop_back();
    }
    segStack.emplace_back(intersection);
  }
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  if (segments.size() == 1) {
    points.push_back(segments[0].end);
    return points;
  }
  // write your code here
  // Sort segments in descending order
  std::sort(segments.begin(), segments.end());
  vector<Segment> SegmentStack;
  for (size_t i = 1; i < segments.size(); ++i) {
    if (i == 1) {
      segment_intersect(segments[0], segments[1], SegmentStack);
    }
    segment_intersect(SegmentStack.back(), segments[i], SegmentStack);
  }
  for (Segment &seg : SegmentStack) {
    points.push_back(seg.end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
