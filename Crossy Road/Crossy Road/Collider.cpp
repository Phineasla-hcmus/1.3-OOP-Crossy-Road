#include "Collider.h"
Collider::Collider(RectangleShape& body) :body(body) {

}
Collider::~Collider() {

}
bool Collider::CheckCollision(Collider& other,float push) {
	Vector2f otherPosition = other.getPosition();
	Vector2f otherHalfSize = other.getHalfSize();

	Vector2f bodyPosition = getPosition();
	Vector2f bodyHalfSize = getHalfSize();

	float deltaX, deltaY, intersectX, intersectY;

	deltaX = otherPosition.x - bodyPosition.x;
	deltaY = otherPosition.y - bodyPosition.y;

	intersectX = abs(deltaX) - (otherHalfSize.x + bodyHalfSize.x);
	intersectY = abs(deltaY) - (otherHalfSize.y + bodyHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		push = min(max(push, 0.0f), 1.0f);
		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else {
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}
		return true;
	}
	return false;
}