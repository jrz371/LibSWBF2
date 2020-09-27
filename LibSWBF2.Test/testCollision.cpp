#include "LibSWBF2.h"
#include "FileWriter.h"
#include "Chunks/LVL/LVL.h"
#include "Types/Enums.h"

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using LibSWBF2::Types::String;
using LibSWBF2::Types::List;

using namespace LibSWBF2::Chunks::LVL;
using namespace LibSWBF2::Wrappers;

using LibSWBF2::Container;
using LibSWBF2::Logging::Logger;
using LibSWBF2::Logging::LoggerEntry;


#define COUT(x) std::cout << x << std::endl

void libLog(const LoggerEntry* log){ COUT(log->ToString().Buffer()); }



int main()
{
	Logger::SetLogCallback(&libLog);

	const char *path;

#ifdef __APPLE__
	path = "/Users/will/Desktop/geo1.lvl";
#else
	path = "/home/will/Desktop/geo1.lvl";
#endif

	Container *container = Container::Create();
	auto handle = container -> AddLevel(path);
	container -> StartLoading();

	while (!container -> IsDone())
	{
		usleep(100000);
	}

	Level *testLVL = container -> GetLevel(handle);



	const List<Model>& models = testLVL -> GetModels();

	for (int i = 0; i < models.Size(); i++)
	{
		const Model& modeli = models[i];
		COUT("On model " << i);
		COUT(modeli.GetName().Buffer());
		
		const List<CollisionPrimitive>& prims = modeli.GetCollisionPrimitives();
		CollisionMesh mesh  			  = modeli.GetCollisionMesh();

		COUT("\n\tPrimitives: ");

		for (int i = 0; i < prims.Size(); i++)
		{
			COUT("\t\t" << prims[i].ToString().Buffer());
		}

		COUT("\tMesh: ");

		uint32_t numIndices, numVertices;
		uint32_t *indices;
		Vector3* verts;

		mesh.GetIndexBuffer(LibSWBF2::ETopology::TriangleList, numIndices, indices);
		COUT("GOT INDICES");
		
		mesh.GetVertexBuffer(numVertices, verts);
		COUT("GOT VERTICES");

		COUT("\t\tIndicies length: " << numIndices);
		COUT("\t\tVertices length: " << numVertices << "\n");
	}
	
	return 0;
}