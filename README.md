Geometrics
==========

Geometrics is a shape editor that allows you to design different geometrical shapes using the command line.
It handles lines, polylines, rectangles, circles and objects that aggregate the previous ones. 

Geometrics allows you to create a model, in which you can add, delete, move shapes and delete them. You can also save and clear the model,load shapes from a file and undo/redo your work.

For further information, you can check the /doc folder. 

## Build

Run the following commands:
```
  cd src
  make
  ./Geometric
```
You can exit the programm by running: `EXIT`.

## Examples

  * C name x y : creates a circle.
  * R name x1 y1 x2 y2 : creates a rectangle.
  * L name x1 y1 x2 y2 : creates a line.
  * OA name object1...objectN : aggregates object1..objectN in the object name. They should be created before.
  * MOVE name x y : increment or decrement the position of name with (x,y).
  * UNDO 
  * REDO
  * DELETE name
  * CLEAR : empties the model from the previously created shapes.
  * SAVE fileName : saves the current model into a file.
  * LOAD fileName: adds to the current model all the shapes described in the file.
  * LIST: displays all the shapes in the current model.

  
