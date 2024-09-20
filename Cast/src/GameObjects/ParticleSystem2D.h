#pragma once

#include <raylib.h>
#include <vector>

struct Particle {
    Vector2 position;
    Vector2 velocity;
    Color color;
    float lifetime;
    float scale;
    float rotation;
    bool active;
};

class ParticleSystem2D {
public:
    ParticleSystem2D(int maxParticles);

    void Emit(const Vector2& position, const Vector2& velocity, const Color& color,
        float lifetime, float scale = 1.0f, float rotation = 0.0f);
    void Update(float deltaTime);
    void Draw(const Camera2D& camera) const;

private:
    std::vector<Particle> particles;
    int maxParticles;
};