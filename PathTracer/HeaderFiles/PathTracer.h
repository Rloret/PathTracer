#pragma once
class Scene;
class Camera;
class Image;
class PathTracer {
public:
	Scene*  m_Scene;
	Camera* m_Camera;
	Image*  m_Img;
	
	PathTracer();

	void TraceRays();
};