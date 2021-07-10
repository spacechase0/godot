#ifndef SCENE_NODECOMPONENT_H
#define SCENE_NODECOMPONENT_H

#include "core/object.h"
#include "core/reference.h"

class NodeComponent : public Reference
{
    GDCLASS( NodeComponent, Reference );
    OBJ_CATEGORY( "Components" );

protected:
    static void _bind_methods();

public:
    //Ref<NodeComponent> duplicate() const;

    virtual String get_component_name() const;

    virtual ~NodeComponent();
};

#endif // SCENE_NODECOMPONENT_H