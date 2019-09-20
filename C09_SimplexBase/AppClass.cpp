#include "AppClass.h"
#include "MyMesh.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Justin Morris - jgm1844@rit.edu";

	////Alberto needed this at this position for software recording.
	//m_pWindow->setPosition(sf::Vector2i(710, 0));

	//m_pTriangle = MyMesh::MakeTriangle(0.5f);
	m_pQuad = MyMesh::MakeQuad(0.5f);
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	//m_uRenderCallCount = m_pMeshMngr->Render();
	if (m_pTriangle != nullptr)
		m_pTriangle->Draw();
	if (m_pQuad != nullptr)
		m_pQuad->Draw();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//release GUI
	ShutdownGUI();
}