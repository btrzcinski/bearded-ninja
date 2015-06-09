// Binary Search
// 
// Call 'bsearch' with a list and a search term. Returns an index containing the term if it is found; -1 otherwise.

let midp first last = (last + first) / 2

let rec rbsearch (l : 'T list) first last (term : 'T) =
    let p = midp first last
    if first > last then
        -1
    elif l.[p] = term then
        p
    elif first = last then
        -1
    elif l.[p] > term then
        rbsearch l first (p - 1) term
    else
        rbsearch l (p + 1) last term

let bsearch (l : 'T list) (term : 'T) = rbsearch l 0 (l.Length - 1) term

[<EntryPoint>]
let main argv =
    let source = [0;1;1;1;1;2;3;6;7;13;16;17;18]
    let searchTerms = [0;1;3;4;5;6;9;11;13]
    let results = List.map (fun x -> bsearch source x) searchTerms
    printfn "Source: %A" source
    printfn "Results: %A" (List.zip searchTerms results)
    0 // return an integer exit code
