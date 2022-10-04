set_bg_colour(1.0, 0.0, 0.0)

function step3()
    local a = test_err()
end

function step2()
    local a = step3()
end

function step1()
    local a = step2()
end

function test_call()
    set_bg_colour(0.0, 1.0, 1.0)
end

set_bg_colour("text")