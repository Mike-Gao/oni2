open Oni_Model;
open Revery_UI;

module Option = Oni_Core.Utility.Option;

let make = (~state: State.t, ()) => {
  let onNodeClick = node =>
    GlobalContext.current().dispatch(
      FileExplorer(FileExplorer.NodeClicked(node)),
    );

  switch (state.fileExplorer) {
  | {tree: None, _} => React.empty
  | {tree: Some(tree), focus, _} =>
    <FileTreeView state focus onNodeClick title="Explorer" tree />
  };
};
