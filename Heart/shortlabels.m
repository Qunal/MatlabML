function short_labels = shortlabels(labels )
%SHORTLABELS

% Find location of capital letters
capital_idx = regexp(labels, '[A-Z]');

capital_idx = cellfun(@(idx) union(idx,1),capital_idx,'UniformOutput',false);

% Only keep capital letters or starting letters for short label
short_labels = cellfun(@(label,idx)  label(idx),labels,capital_idx,'UniformOutput',false);


end

