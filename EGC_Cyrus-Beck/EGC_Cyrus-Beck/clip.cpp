#include "clip.h"
#include "vec3.h"

namespace egc {

	//Cyrus-Beck clipping algorithm
	//clipWindow specifies the vertices that define the clipping area in conterclockwise order
	//and can represent any convex polygon
	//function returns -1 if the line segment cannot be clipped

	float max(float a, float b) {
		if (a > b) return a;
		return b;
	}

	float min(float a, float b) {
		if (a < b) return a;
		return b;
	}
	int lineClip_CyrusBeck(std::vector<vec3> clipWindow, vec3& p1, vec3& p2) {
		//TO DO - implement the Cyrus-Beck line clipping algorithm - consult the laboratory work
		std::vector<vec3> normal = std::vector<vec3>(clipWindow.size());
		std::vector<vec3> pei = std::vector<vec3>(clipWindow.size());

		vec3 z = vec3(0, 0, -1);
		if (p1 == p2) return 0;
		for (int i = 0; i < clipWindow.size(); i++) {
			pei[i] = clipWindow[i];
			normal[i] = crossProduct(clipWindow[(i + 1) % clipWindow.size()] - clipWindow[i], z);
		}
		
		float  t = 0, tE = 0, tL = 1;
		vec3 D = p2 - p1;
		for (int i = 0; i < clipWindow.size(); i++) {
			float dot = dotProduct(normal[i], D);
			if (dot != 0) {
				t = dotProduct(normal[i], p1 - pei[i]) / (-dot);
				if (dot < 0) {
					tE = max(tE, t);
				}
				else {
					tL = min(tL, t);
				}
			}
		}

		if (tE > tL) {
			return -1;
		}

		vec3 v1 = p1;
		vec3 v2 = p2;

		p1 = v1 + (v2 - v1) * tE;
		p2 = v1 + (v2 - v1) * tL;
		return 0;
	}

	
}

