/* Copyright (c) 2014, Stanislaw Halik <sthalik@misaki.pl>

 * Permission to use, copy, modify, and/or distribute this
 * software for any purpose with or without fee is hereby granted,
 * provided that the above copyright notice and this permission
 * notice appear in all copies.
 */

#include "test.h"
#include "tracker.h"
#include "api/plugin-api.hpp"
#include "compat/math-imports.hpp"

#include <QPushButton>

#include <cmath>
#include <QDebug>


test_dialog::test_dialog()
{
    ui.setupUi(this);

    connect(ui.buttonBox, &QDialogButtonBox::clicked, [this](QAbstractButton* btn) {
        if (btn == ui.buttonBox->button(QDialogButtonBox::Abort))
            // NOLINTNEXTLINE
            *(volatile int*)nullptr = 0;
    });

    connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(doOK()));
    connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(doCancel()));
}

void test_dialog::doOK()
{
    //s.b->save();
    close();
}

void test_dialog::doCancel()
{
    close();
}

OPENTRACK_DECLARE_TRACKER(KinectFaceTracker, test_dialog, test_metadata)
