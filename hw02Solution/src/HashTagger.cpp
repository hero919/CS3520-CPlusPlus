#include "HashTagger.h"
#include <iostream>
using namespace std;
using namespace hw02;

void HashTagger::getTags(const string& line) noexcept {

  // Loop over all characters in the line

  for (unsigned int i = 0; i < line.length(); ++i) {
    if (line.at(i) == '#') {

      // A hashtag has been found, it ends at
      // either a space of the end of the line.

      string tag;
      for (unsigned int j = i+1; j < line.length(); ++j) {
	char c = line.at(j);
	if (c == ' ' || c == '.' || c == '!' || c == '?') {
	  tag = line.substr(i, j-i);
	  break;
	}
      }

      // If a tag was found, then add it to the
      // list; otherwise, the tag ended at the end
      // of the line, so it must also be added to
      // the list.

      if (tag.length() == 0) {
	tag = line.substr(i);
      }
      list_.push_back(tag);
    }
  }
}

void HashTagger::printTags() const noexcept {
  for (const string& tag : list_) {
    cout << tag << endl;
  }
}
